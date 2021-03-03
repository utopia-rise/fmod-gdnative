#include "file_callbacks.h"
#include <OS.hpp>
#include "../helpers/macro.h"

namespace Callbacks{

    GodotFileRunner* GodotFileRunner::get_singleton() {
        static GodotFileRunner singleton;
        return &singleton;
    }

    void GodotFileRunner::queueReadRequest(FMOD_ASYNCREADINFO* request, ReadPriority priority) {
        //High priority requests have to be processed first.
        if(priority == ReadPriority::HIGH) {
            //lock so we can't add and remove elements from the queue at the same time.
            GODOT_LOG(0, "Read lock Queue Request")
            std::lock_guard<std::mutex> lk(read_mut);
            requests.push_front_value(request);
            GODOT_LOG(0, "Read Unlock Queue Request")
        }
        else{
            //lock so we can't add and remove elements from the queue at the same time.
            GODOT_LOG(0, "Read lock Queue Request")
            std::lock_guard<std::mutex> lk(read_mut);
            requests.push_back_value(request);
            GODOT_LOG(0, "Read Unlock Queue Request")
        }
        read_cv.notify_one();
        GODOT_LOG(0, "Read Notification")
    }

    void GodotFileRunner::cancelReadRequest(FMOD_ASYNCREADINFO* request) {
        //lock so we can't add and remove elements from the queue at the same time.
        {
            GODOT_LOG(0, "Read Lock Cancel Request")
            std::lock_guard<std::mutex> lk(read_mut);
            requests.erase(request);
            GODOT_LOG(0, "Read UnLock Cancel Request")
        }

        //We lock and check if the current request is the one being canceled.
        //In this case, we wait until it's done.
        {
            std::unique_lock<std::mutex> lk(cancel_mut);
            if(request == current_request){
                GODOT_LOG(0, "Waiting for cancel notification")
                cancel_cv.wait(lk);
            }
        }
    }

    void GodotFileRunner::run() {
        while(!stop) {

            //waiting for the container to have one request
            {
                std::unique_lock<std::mutex> lk(read_mut);
                GODOT_LOG(0, "Waiting for read notification")
                read_cv.wait(lk, [this]{return !requests.empty() || stop;});
            }

            while(!requests.empty()) {
                //lock so we can't add and remove elements from the queue at the same time.
                //also store the current request so it cannot be cancel during process.
                {
                    GODOT_LOG(0, "Read lock Run")
                    std::lock_guard<std::mutex> lk(read_mut);
                    current_request = requests.pop_front_value();
                    GODOT_LOG(0, "Read Unlock Run")
                }

                //We get the Godot File object from the handle
                GodotFileHandle* handle {reinterpret_cast<GodotFileHandle*>(current_request->handle)};
                godot::Ref<godot::File> file {handle->file};

                //update the position of the cursor
                file->seek(current_request->offset);

                //We read and store the requested data in an array.
                godot::PoolByteArray buffer {file->get_buffer(current_request->sizebytes)};
                int size {buffer.size()};
                const uint8_t* data {buffer.read().ptr()};

                //We copy the data to FMOD buffer
                memcpy(current_request->buffer, data, size * sizeof(uint8_t));
                current_request->bytesread = size;

                //Don't forget the return an error if end of the file is reached
                FMOD_RESULT result;
                if(file->eof_reached()) {
                    result = FMOD_RESULT::FMOD_ERR_FILE_EOF;
                }
                else {
                    result = FMOD_RESULT::FMOD_OK;
                }
                current_request->done(current_request, result);

                //Request no longer processed
                {
                    GODOT_LOG(0, "Cancel Lock Run")
                    std::lock_guard<std::mutex> lk(cancel_mut);
                    current_request = nullptr;
                    GODOT_LOG(0, "Cancel UnLock Run")
                }
                cancel_cv.notify_one();
                GODOT_LOG(0, "Cancel Notification")
            }
        }
    }

    void GodotFileRunner::start() {
        stop = false;
        fileThread = std::thread(&GodotFileRunner::run, this);
    }

    void GodotFileRunner::finish(){
        stop = true;
        //we need to notify the loop one last time, otherwise it will stay stuck in the wait method.
        read_cv.notify_one();
        fileThread.join();

    }


    FMOD_RESULT F_CALLBACK godotFileOpen(
            const char *name,
            unsigned int *filesize,
            void **handle,
            void *userdata
    ) {
        godot::Ref<godot::File> file;
        file.instance();

        GodotFileHandle* fileHandle {new GodotFileHandle{file}};

        godot::Error err = file->open(name, godot::File::ModeFlags::READ);
        *filesize = file->get_len();
        *handle = reinterpret_cast<void *>(fileHandle);

        if(err == godot::Error::OK) {
            return FMOD_RESULT::FMOD_OK;
        }
        return FMOD_RESULT::FMOD_ERR_FILE_BAD;
    }

    FMOD_RESULT F_CALLBACK godotFileClose(
            void *handle,
            void *userdata
    ) {
        godot::Ref<godot::File> file {reinterpret_cast<GodotFileHandle*>(handle)->file};
        file->close();
        delete reinterpret_cast<GodotFileHandle*>(handle);
        return FMOD_RESULT::FMOD_OK;
    }

    FMOD_RESULT F_CALLBACK godotSyncRead(
            FMOD_ASYNCREADINFO *info,
            void *userdata
    ) {
        GodotFileRunner* runner {GodotFileRunner::get_singleton()};
        int priority {info->priority};

        GodotFileRunner::ReadPriority priorityRank;
        if(priority == 100){
            priorityRank = GodotFileRunner::ReadPriority::HIGH;
        }
        else {
            priorityRank = GodotFileRunner::ReadPriority::NORMAL;
        }
        runner->queueReadRequest(info, priorityRank);
        return FMOD_RESULT::FMOD_OK;
    }

    FMOD_RESULT F_CALLBACK godotSyncCancel(
            FMOD_ASYNCREADINFO *info,
            void *userdata
    ) {
        GodotFileRunner* runner {GodotFileRunner::get_singleton()};
        runner->cancelReadRequest(info);
        return FMOD_RESULT::FMOD_OK;
    }
}