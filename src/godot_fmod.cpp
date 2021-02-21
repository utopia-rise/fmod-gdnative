//
// Created by Pierre-Thomas Meisels on 2019-01-01.
//

#include "godot_fmod.h"

using namespace godot;

bool Fmod::verboseMode = true;

Fmod::Fmod() = default;

Fmod::~Fmod() {
    Callbacks::GodotFileRunner::get_singleton()->finish();
}

void Fmod::_register_methods() {
    register_method("init", &Fmod::init);
    register_method("shutdown", &Fmod::shutdown);
    register_method("add_listener", &Fmod::addListener);
    register_method("remove_listener", &Fmod::removeListener);
    register_method("set_listener_number", &Fmod::setListenerNumber);
    register_method("get_listener_number", &Fmod::getSystemNumListeners);
    register_method("get_listener_weight", &Fmod::getSystemListenerWeight);
    register_method("set_listener_weight", &Fmod::setSystemListenerWeight);
    register_method("get_listener_3D_attributs", &Fmod::getSystemListener3DAttributes);
    register_method("get_listener_2D_attributs", &Fmod::getSystemListener2DAttributes);
    register_method("set_listener_3D_attributs", &Fmod::setSystemListener3DAttributes);
    register_method("set_listener_2D_attributs", &Fmod::setSystemListener2DAttributes);
    register_method("set_listener_lock", &Fmod::setListenerLock);
    register_method("get_listener_lock", &Fmod::getListenerLock);
    register_method("get_object_attached_to_listener", &Fmod::getObjectAttachedToListener);
    register_method("set_software_format", &Fmod::setSoftwareFormat);
    register_method("load_bank", &Fmod::loadBank);
    register_method("unload_bank", &Fmod::unloadBank);
    register_method("check_VCA_path", &Fmod::checkVCAPath);
    register_method("check_bus_path", &Fmod::checkBusPath);
    register_method("check_event_path", &Fmod::checkEventPath);
    register_method("get_bank_loading_state", &Fmod::getBankLoadingState);
    register_method("get_bank_bus_count", &Fmod::getBankBusCount);
    register_method("get_bank_event_count", &Fmod::getBankEventCount);
    register_method("get_bank_string_count", &Fmod::getBankStringCount);
    register_method("get_bank_VCA_count", &Fmod::getBankVCACount);
    register_method("create_event_instance", &Fmod::createEventInstance);
    register_method("get_event_parameter_by_name", &Fmod::getEventParameterByName);
    register_method("set_event_parameter_by_name", &Fmod::setEventParameterByName);
    register_method("get_event_parameter_by_id", &Fmod::getEventParameterByID);
    register_method("set_event_parameter_by_id", &Fmod::setEventParameterByID);
    register_method("release_event", &Fmod::releaseEvent);
    register_method("start_event", &Fmod::startEvent);
    register_method("stop_event", &Fmod::stopEvent);
    register_method("trigger_event_cue", &Fmod::triggerEventCue);
    register_method("get_event_playback_state", &Fmod::getEventPlaybackState);
    register_method("get_event_paused", &Fmod::getEventPaused);
    register_method("set_event_paused", &Fmod::setEventPaused);
    register_method("get_event_pitch", &Fmod::getEventPitch);
    register_method("set_event_pitch", &Fmod::setEventPitch);
    register_method("get_event_volume", &Fmod::getEventVolume);
    register_method("set_event_volume", &Fmod::setEventVolume);
    register_method("get_event_timeline_position", &Fmod::getEventTimelinePosition);
    register_method("set_event_timeline_position", &Fmod::setEventTimelinePosition);
    register_method("get_event_reverb_level", &Fmod::getEventReverbLevel);
    register_method("set_event_reverb_level", &Fmod::setEventReverbLevel);
    register_method("is_event_virtual", &Fmod::isEventVirtual);
    register_method("set_event_listener_mask", &Fmod::setEventListenerMask);
    register_method("get_event_listener_mask", &Fmod::getEventListenerMask);
    register_method("set_event_2d_attributes", &Fmod::setEvent2DAttributes);
    register_method("get_event_2d_attributes", &Fmod::getEvent2DAttributes);
    register_method("set_event_3d_attributes", &Fmod::setEvent3DAttributes);
    register_method("get_event_3d_attributes", &Fmod::getEvent3DAttributes);
    register_method("desc_get_length", &Fmod::descGetLength);
    register_method("desc_get_instance_list", &Fmod::descGetInstanceList);
    register_method("desc_get_instance_count", &Fmod::descGetInstanceCount);
    register_method("desc_release_all_instances", &Fmod::descReleaseAllInstances);
    register_method("desc_load_sample_data", &Fmod::descLoadSampleData);
    register_method("desc_unload_sample_data", &Fmod::descUnloadSampleData);
    register_method("desc_get_sample_loading_state", &Fmod::descGetSampleLoadingState);
    register_method("desc_is_3d", &Fmod::descIs3D);
    register_method("desc_is_one_shot", &Fmod::descIsOneShot);
    register_method("desc_is_snapshot", &Fmod::descIsSnapshot);
    register_method("desc_is_stream", &Fmod::descIsStream);
    register_method("desc_has_cue", &Fmod::descHasCue);
    register_method("desc_get_maximum_distance", &Fmod::descGetMaximumDistance);
    register_method("desc_get_minimum_distance", &Fmod::descGetMinimumDistance);
    register_method("desc_get_sound_size", &Fmod::descGetSoundSize);
    register_method("desc_get_parameter_description_by_name", &Fmod::descGetParameterDescriptionByName);
    register_method("desc_get_parameter_description_by_id", &Fmod::descGetParameterDescriptionByID);
    register_method("desc_get_parameter_description_count", &Fmod::descGetParameterDescriptionCount);
    register_method("desc_get_parameter_description_by_index", &Fmod::descGetParameterDescriptionByIndex);
    register_method("desc_get_user_property", &Fmod::descGetUserProperty);
    register_method("desc_get_user_property_count", &Fmod::descGetUserPropertyCount);
    register_method("desc_user_property_by_index", &Fmod::descUserPropertyByIndex);
    register_method("get_bus_mute", &Fmod::getBusMute);
    register_method("get_bus_paused", &Fmod::getBusPaused);
    register_method("get_bus_volume", &Fmod::getBusVolume);
    register_method("set_bus_mute", &Fmod::setBusMute);
    register_method("set_bus_paused", &Fmod::setBusPaused);
    register_method("set_bus_volume", &Fmod::setBusVolume);
    register_method("stop_all_bus_events", &Fmod::stopAllBusEvents);
    register_method("get_VCA_volume", &Fmod::getVCAVolume);
    register_method("set_VCA_volume", &Fmod::setVCAVolume);
    register_method("play_one_shot", &Fmod::playOneShot);
    register_method("play_one_shot_with_params", &Fmod::playOneShotWithParams);
    register_method("play_one_shot_attached", &Fmod::playOneShotAttached);
    register_method("play_one_shot_attached_with_params", &Fmod::playOneShotAttachedWithParams);
    register_method("attach_instance_to_node", &Fmod::attachInstanceToNode);
    register_method("detach_instance_from_node", &Fmod::detachInstanceFromNode);
    register_method("get_object_attached_to_instance", &Fmod::getObjectAttachedToInstance);
    register_method("pause_all_events", &Fmod::pauseAllEvents);
    register_method("mute_all_events", &Fmod::muteAllEvents);
    register_method("unmute_all_events", &Fmod::unmuteAllEvents);
    register_method("banks_still_loading", &Fmod::banksStillLoading);
    register_method("load_file_as_sound", &Fmod::loadFileAsSound);
    register_method("load_file_as_music", &Fmod::loadFileAsMusic);
    register_method("unload_file", &Fmod::unloadFile);
    register_method("create_sound_instance", &Fmod::createSoundInstance);
    register_method("check_sound_instance", &Fmod::checkSoundInstance);
    register_method("release_sound", &Fmod::releaseSound);
    register_method("play_sound", &Fmod::playSound);
    register_method("stop_sound", &Fmod::stopSound);
    register_method("set_sound_paused", &Fmod::setSoundPaused);
    register_method("is_sound_playing", &Fmod::isSoundPlaying);
    register_method("set_sound_volume", &Fmod::setSoundVolume);
    register_method("get_sound_volume", &Fmod::getSoundVolume);
    register_method("set_sound_pitch", &Fmod::setSoundPitch);
    register_method("get_sound_pitch", &Fmod::getSoundPitch);
    register_method("set_callback", &Fmod::setCallback);
    register_method("set_sound_3D_settings", &Fmod::setSound3DSettings);
    register_method("wait_for_all_loads", &Fmod::waitForAllLoads);
    register_method("get_available_drivers", &Fmod::getAvailableDrivers);
    register_method("get_driver", &Fmod::getDriver);
    register_method("set_driver", &Fmod::setDriver);
    register_method("get_performance_data", &Fmod::getPerformanceData);
    register_method("set_global_parameter_by_name", &Fmod::setGlobalParameterByName);
    register_method("get_global_parameter_by_name", &Fmod::getGlobalParameterByName);
    register_method("set_global_parameter_by_id", &Fmod::setGlobalParameterByID);
    register_method("get_global_parameter_by_id", &Fmod::getGlobalParameterByID);
    register_method("get_global_parameter_desc_by_name", &Fmod::getGlobalParameterDescByName);
    register_method("get_global_parameter_desc_by_id", &Fmod::getGlobalParameterDescByID);
    register_method("get_global_parameter_desc_count", &Fmod::getGlobalParameterDescCount);
    register_method("get_global_parameter_desc_list", &Fmod::getGlobalParameterDescList);
    register_method("_process", &Fmod::_process);

    register_property<Fmod, bool>("verbose_mode", &Fmod::setVerboseMode, &Fmod::getVerboseMode, false);

    register_signal<Fmod>("timeline_beat", "params", GODOT_VARIANT_TYPE_DICTIONARY);
    register_signal<Fmod>("timeline_marker", "params", GODOT_VARIANT_TYPE_DICTIONARY);
    register_signal<Fmod>("sound_played", "params", GODOT_VARIANT_TYPE_DICTIONARY);
    register_signal<Fmod>("sound_stopped", "params", GODOT_VARIANT_TYPE_DICTIONARY);

    REGISTER_ALL_CONSTANTS
}

void Fmod::setVerboseMode(bool value) {
    verboseMode = value;
}

bool Fmod::getVerboseMode() {
    return verboseMode;
}

bool Fmod::checkErrors(FMOD_RESULT result, const char *function, const char *file, int line) {
    if (result != FMOD_OK) {
        godot::Godot::print_error(FMOD_ErrorString(result), function, file, line);
        return false;
    }
    return true;
}

void Fmod::init(int numOfChannels, const unsigned int studioFlag, const unsigned int flag) {
    // initialize FMOD Studio and FMOD Core System with provided flags
    if (system == nullptr && coreSystem == nullptr) {
        ERROR_CHECK(FMOD::Studio::System::create(&system));
        ERROR_CHECK(system->getCoreSystem(&coreSystem));
    }

    if (ERROR_CHECK(system->initialize(numOfChannels, studioFlag, flag, nullptr))) {
        isInitialized = true;
        GODOT_LOG(0, "FMOD Sound System: Successfully initialized")
        if (studioFlag == FMOD_STUDIO_INIT_LIVEUPDATE) {
            GODOT_LOG(0, "FMOD Sound System: Live update enabled!")
        }
    }

#ifdef CUSTOM_FILESYSTEM
    if (ERROR_CHECK(coreSystem->setFileSystem(
            &Callbacks::godotFileOpen,
            &Callbacks::godotFileClose,
            nullptr,
            nullptr,
            &Callbacks::godotSyncRead,
            &Callbacks::godotSyncCancel,
            -1)
    )) {
        GODOT_LOG(0, "Custom File System enabled.")
    }
#endif
}

void Fmod::_process(float delta) {
    if (!isInitialized) {
        if (!isNotinitPrinted) {
            GODOT_LOG(2, "FMOD Sound System: Fmod should be initialized before calling update")
            isNotinitPrinted = true;
        }
        return;
    }

    //Check if bank are loaded, load buses, vca and event descriptions.
    checkLoadingBanks();

    for (int i = 0; i < events.size(); i++) {
        FMOD::Studio::EventInstance *eventInstance = events.get(i);
        if (eventInstance) {
            EventInfo *eventInfo = getEventInfo(eventInstance);
            if (eventInfo) {
                if (eventInfo->gameObj) {
                    if (isDead(eventInfo->gameObj)) {
                        FMOD_STUDIO_STOP_MODE m = FMOD_STUDIO_STOP_IMMEDIATE;
                        ERROR_CHECK(eventInstance->stop(m));
                        releaseOneEvent(eventInstance);
                        i--;
                        continue;
                    }
                    if (eventInfo->isOneShot) {
                        FMOD_STUDIO_PLAYBACK_STATE s;
                        ERROR_CHECK(eventInstance->getPlaybackState(&s));
                        if (s == FMOD_STUDIO_PLAYBACK_STOPPED) {
                            releaseOneEvent(eventInstance);
                            i--;
                            continue;
                        }
                    }
                    updateInstance3DAttributes(eventInstance, eventInfo->gameObj);
                }
            } else {
                GODOT_LOG(2, "A managed event doesn't have an EventInfoStructure")
            }
        }
    }

    for (int i = 0; i < channels.size(); i++) {
        FMOD::Channel *channel = channels.get(i);
        if (channel && !isChannelValid(channel)) {
            channels.erase(channel);
            i--;
        }
    }

    // update listener position
    setListenerAttributes();

    //run callback events
    runCallbacks();

    // dispatch update to FMOD
    ERROR_CHECK(system->update());
}

void Fmod::checkLoadingBanks() {
    for (int i = 0; i < loadingBanks.size(); i++) {
        auto loadingBank = loadingBanks.pop_front_value();
        auto bank = loadingBank->bank;
        FMOD_STUDIO_LOADING_STATE *loading_state = nullptr;
        ERROR_CHECK(bank->getLoadingState(loading_state));
        if (*loading_state == FMOD_STUDIO_LOADING_STATE_LOADED) {
            loadBankData(loadingBank);
            delete loadingBank;
        } else if (*loading_state == FMOD_STUDIO_LOADING_STATE_LOADING) {
            loadingBanks.push_back_value(loadingBank);
        } else if (*loading_state == FMOD_STUDIO_LOADING_STATE_ERROR) {
            bank->unload();
            delete loadingBank;
            GODOT_LOG(2, "Fmod Sound System: Error loading bank.")
        }
    }
}

void Fmod::setListenerAttributes() {
    if (actualListenerNumber == 0) {
        if (listenerWarning) {
            GODOT_LOG(1, "FMOD Sound System: No listeners are set!")
            listenerWarning = false;
        }
        return;
    }

    for (int i = 0; i < systemListenerNumber; i++) {
        Listener* listener = &listeners[i];
        if (listener->listenerLock) {
            continue;
        }
        if (isDead(listener->gameObj)) {
            listener->gameObj = nullptr;
            ERROR_CHECK(system->setListenerWeight(i, 0));
            continue;
        }

        Node* node {listener->gameObj};
        if(!node->is_inside_tree()){
            return;
        }

        if (auto *ci {Node::cast_to<CanvasItem>(node)}) {
            auto attr = get3DAttributesFromTransform2D(ci->get_global_transform());
            ERROR_CHECK(system->setListenerAttributes(i, &attr));
            continue;
        }

        if (auto *s {Node::cast_to<Spatial>(node)}) {
            auto attr = get3DAttributesFromTransform(s->get_global_transform());
            ERROR_CHECK(system->setListenerAttributes(i, &attr));
            continue;
        }
    }
}

FMOD_VECTOR Fmod::toFmodVector(Vector3 &vec) {
    FMOD_VECTOR fv;
    fv.x = vec.x;
    fv.y = vec.y;
    fv.z = vec.z;
    return fv;
}

FMOD_3D_ATTRIBUTES Fmod::get3DAttributes(const FMOD_VECTOR &pos, const FMOD_VECTOR &up, const FMOD_VECTOR &forward,
                                         const FMOD_VECTOR &vel) {
    FMOD_3D_ATTRIBUTES
            f3d;
    f3d.forward = forward;
    f3d.position = pos;
    f3d.up = up;
    f3d.velocity = vel;
    return f3d;
}

FMOD_3D_ATTRIBUTES Fmod::get3DAttributesFromTransform(const Transform transform) {
    Vector3 pos = transform.get_origin() / distanceScale;
    Vector3 up = transform.get_basis().elements[1];
    Vector3 forward = transform.get_basis().elements[2];
    Vector3 vel(0, 0, 0);
    return get3DAttributes(toFmodVector(pos), toFmodVector(up), toFmodVector(forward), toFmodVector(vel));
}

FMOD_3D_ATTRIBUTES Fmod::get3DAttributesFromTransform2D(const Transform2D transform) {
    Vector2 posVector = transform.get_origin() / distanceScale;
    Vector3 pos(posVector.x, 0.0f, posVector.y);
    Vector3 up(0, 1, 0);
    Vector3 forward = Vector3(transform.elements[1].x, 0, transform.elements[1].y).normalized();
    Vector3 vel(0, 0, 0); // TODO: add doppler
    const FMOD_VECTOR &posFmodVector = toFmodVector(pos);
    return get3DAttributes(posFmodVector, toFmodVector(up), toFmodVector(forward), toFmodVector(vel));
}

Dictionary Fmod::getTransformInfoFrom3DAttribut(FMOD_3D_ATTRIBUTES &attr) {
    Dictionary _3Dattr;
    Transform transform;
    transform.origin = Vector3(attr.position.x, attr.position.y, attr.position.z) * distanceScale;
    const Vector3 &upVector = Vector3(attr.up.x, attr.up.y, attr.up.z);
    transform.basis.elements[1] = upVector;
    const Vector3 &forwardVector = Vector3(attr.forward.x, attr.forward.y, attr.forward.z);
    transform.basis.elements[2] = forwardVector;
    transform.basis.elements[0] = upVector.cross(forwardVector);
    Vector3 velocity(attr.velocity.x, attr.velocity.y, attr.velocity.z);
    _3Dattr["transform"] = transform;
    _3Dattr["velocity"] = velocity;
    return _3Dattr;
}

Dictionary Fmod::getTransform2DInfoFrom3DAttribut(FMOD_3D_ATTRIBUTES &attr) {
    Dictionary _2Dattr;
    Transform2D transform;
    transform.set_origin(Vector2(attr.position.x, attr.position.z) * distanceScale);
    const Vector2 &forward = Vector2(attr.forward.x, attr.forward.z);
    transform.elements[1] = forward;
    transform.elements[0] = Vector2(forward.y, -forward.x);
    Vector2 velocity(attr.velocity.x, attr.velocity.z);
    _2Dattr["transform"] = transform;
    _2Dattr["velocity"] = velocity;
    return _2Dattr;
}

bool Fmod::isDead(Node *node) {
    if (!node) {
        return true;
    }
    return !godot::core_1_1_api->godot_is_instance_valid(node->_owner);
}

bool Fmod::isFmodValid(Node *node) {
    if (node) {
        bool ret = Node::cast_to<Spatial>(node) || Node::cast_to<CanvasItem>(node);
        if(!ret) {
            GODOT_LOG(2, "Invalid Object. A listener has to be either a Spatial or CanvasItem.")
        }
        return ret;
    }
    GODOT_LOG(2, "Object is null")
    return false;
}

void Fmod::updateInstance3DAttributes(FMOD::Studio::EventInstance *instance, Node *node) {
    // try to set 3D attributes
    if (instance && isFmodValid(node) && node->is_inside_tree()) {
        if (auto *ci {Node::cast_to<CanvasItem>(node)}) {
            auto attr = get3DAttributesFromTransform2D(ci->get_global_transform());
            ERROR_CHECK(instance->set3DAttributes(&attr));
            return;
        }
        if (auto *s {Node::cast_to<Spatial>(node)}) {
            auto attr = get3DAttributesFromTransform(s->get_global_transform());
            ERROR_CHECK(instance->set3DAttributes(&attr));
            return;
        }
    }
}

void Fmod::shutdown() {
    isInitialized = false;
    isNotinitPrinted = false;
    ERROR_CHECK(system->unloadAll());
    ERROR_CHECK(system->release());
    system = nullptr;
    coreSystem = nullptr;
    GODOT_LOG(0, "FMOD Sound System: System released")

}

void Fmod::setListenerNumber(int p_listenerNumber) {
    if (p_listenerNumber > 0 && p_listenerNumber <= FMOD_MAX_LISTENERS) {
        if (ERROR_CHECK(system->setNumListeners(p_listenerNumber))) {
            systemListenerNumber = p_listenerNumber;
        }
    } else {
        GODOT_LOG(2, "Number of listeners must be set between 1 and 8")
    }
}

void Fmod::addListener(int index, Node *gameObj) {
    if(!isFmodValid(gameObj)) {
        return;
    }
    if (index >= 0 && index < systemListenerNumber) {
        Listener *listener = &listeners[index];
        listener->gameObj = gameObj;
        ERROR_CHECK(system->setListenerWeight(index, listener->weight));
        int count = 0;
        for (int i = 0; i < systemListenerNumber; i++) {
            auto listener = &listeners[i];
            if (listener->gameObj != nullptr) count++;
        }
        actualListenerNumber = count;
        if (actualListenerNumber > 0) listenerWarning = true;
    } else {
        GODOT_LOG(2, "index of listeners must be set between 0 and the number of listeners set")
    }
}

void Fmod::removeListener(int index) {
    if (index >= 0 && index < systemListenerNumber) {
        Listener *listener = &listeners[index];
        listener->gameObj = nullptr;
        ERROR_CHECK(system->setListenerWeight(index, 0));
        int count = 0;
        for (int i = 0; i < systemListenerNumber; i++) {
            auto listener = &listeners[i];
            if (listener->gameObj != nullptr) count++;
        }
        actualListenerNumber = count;
        if (actualListenerNumber > 0) listenerWarning = true;
    } else {
        GODOT_LOG(2, "index of listeners must be set between 0 and the number of listeners set")
    }
}

int Fmod::getSystemNumListeners() {
    return systemListenerNumber;
}

float Fmod::getSystemListenerWeight(const int index) {
    if (index >= 0 && index < systemListenerNumber) {
        float weight = 0;
        ERROR_CHECK(system->getListenerWeight(index, &weight));
        listeners[index].weight = weight;
        return weight;
    } else {
        GODOT_LOG(2, "index of listeners must be set between 0 and the number of listeners set")
        return 0;
    }

}

void Fmod::setSystemListenerWeight(const int index, float weight) {
    if (index >= 0 && index < systemListenerNumber) {
        listeners[index].weight = weight;
        ERROR_CHECK(system->setListenerWeight(index, weight));
    } else {
        GODOT_LOG(2, "index of listeners must be set between 0 and the number of listeners set")
    }
}

Dictionary Fmod::getSystemListener3DAttributes(const int index) {
    Dictionary _3Dattr;
    if (index >= 0 && index < systemListenerNumber) {
        FMOD_3D_ATTRIBUTES
                attr;
        ERROR_CHECK(system->getListenerAttributes(index, &attr));
        _3Dattr = getTransformInfoFrom3DAttribut(attr);
    } else {
        GODOT_LOG(2, "index of listeners must be set between 0 and the number of listeners set")
    }
    return _3Dattr;
}

Dictionary Fmod::getSystemListener2DAttributes(int index) {
    Dictionary _2Dattr;
    if (index >= 0 && index < systemListenerNumber) {
        FMOD_3D_ATTRIBUTES
                attr;
        ERROR_CHECK(system->getListenerAttributes(index, &attr));
        _2Dattr = getTransform2DInfoFrom3DAttribut(attr);
    } else {
        GODOT_LOG(2, "index of listeners must be set between 0 and the number of listeners set")
    }
    return _2Dattr;
}

void Fmod::setSystemListener3DAttributes(int index, Transform transform) {
    if (index >= 0 && index < systemListenerNumber) {
        FMOD_3D_ATTRIBUTES
                attr = get3DAttributesFromTransform(transform);
        ERROR_CHECK(system->setListenerAttributes(index, &attr));
    } else {
        GODOT_LOG(2, "index of listeners must be set between 0 and the number of listeners set")
    }
}

void Fmod::setSystemListener2DAttributes(int index, Transform2D transform) {
    if (index >= 0 && index < systemListenerNumber) {
        FMOD_3D_ATTRIBUTES
                attr = get3DAttributesFromTransform2D(transform);
        ERROR_CHECK(system->setListenerAttributes(index, &attr));
    } else {
        GODOT_LOG(2, "index of listeners must be set between 0 and the number of listeners set")
    }
}

void Fmod::setListenerLock(int index, bool isLocked) {
    if (index >= 0 && index < systemListenerNumber) {
        listeners[index].listenerLock = isLocked;
    } else {
        GODOT_LOG(2, "index of listeners must be set between 0 and the number of listeners set")
    }
}

bool Fmod::getListenerLock(int index) {
    if (index >= 0 && index < systemListenerNumber) {
        return listeners[index].listenerLock;
    } else {
        GODOT_LOG(2, "index of listeners must be set between 0 and the number of listeners set")
        return false;
    }
}

Node * Fmod::getObjectAttachedToListener(int index) {
    if (index < 0 || index >= systemListenerNumber) {
        GODOT_LOG(2, "index of listeners must be set between 0 and the number of listeners set")
        return nullptr;
    } else {
        Node *node = listeners[index].gameObj;
        if (!node) {
            GODOT_LOG(1, "No node was set on listener")
        }
        return node;
    }
}

void Fmod::setSoftwareFormat(int sampleRate, const int speakerMode, int numRawSpeakers) {
    if (system == nullptr && coreSystem == nullptr) {
        ERROR_CHECK(FMOD::Studio::System::create(&system));
        ERROR_CHECK(system->getCoreSystem(&coreSystem));
    }
    ERROR_CHECK(coreSystem->setSoftwareFormat(sampleRate, static_cast<FMOD_SPEAKERMODE>(speakerMode), numRawSpeakers));
}

String Fmod::loadBank(String pathToBank, const unsigned int flag) {
    DRIVE_PATH(pathToBank)
    if (banks.has(pathToBank)) return pathToBank; // bank is already loaded
    FMOD::Studio::Bank *bank = nullptr;
    ERROR_CHECK(system->loadBankFile(pathToBank.alloc_c_string(), flag, &bank));
    if (bank) {
        GODOT_LOG(0, "FMOD Sound System: LOADING BANK " + String(pathToBank))
        auto *loadingBank = new LoadingBank();
        loadingBank->bank = bank;
        loadingBank->godotPath = pathToBank;
        if (flag != FMOD_STUDIO_LOAD_BANK_NONBLOCKING) {
            loadBankData(loadingBank);
        } else {
            loadingBanks.append(loadingBank);
        }
    }
    return pathToBank;
}

void Fmod::unloadBank(String pathToBank) {
    DRIVE_PATH(pathToBank)
    FIND_AND_CHECK(pathToBank, banks)
    unloadAllBuses(instance);
    unloadAllVCAs(instance);
    unloadAllEventDescriptions(instance);
    ERROR_CHECK(instance->unload());
    GODOT_LOG(0, "FMOD Sound System: BANK " + String(pathToBank) + " UNLOADED")
    banks.erase(pathToBank);
}

int Fmod::getBankLoadingState(String pathToBank) {
    DRIVE_PATH(pathToBank)
    FIND_AND_CHECK(pathToBank, banks, -1)
    FMOD_STUDIO_LOADING_STATE state;
    ERROR_CHECK(instance->getLoadingState(&state));
    return state;
}

int Fmod::getBankBusCount(String pathToBank) {
    DRIVE_PATH(pathToBank)
    FIND_AND_CHECK(pathToBank, banks, -1)
    int count = -1;
    ERROR_CHECK(instance->getBusCount(&count));
    return count;
}

int Fmod::getBankEventCount(String pathToBank) {
    DRIVE_PATH(pathToBank)
    FIND_AND_CHECK(pathToBank, banks, -1)
    int count = -1;
    ERROR_CHECK(instance->getEventCount(&count));
    return count;
}

int Fmod::getBankStringCount(String pathToBank) {
    DRIVE_PATH(pathToBank)
    FIND_AND_CHECK(pathToBank, banks, -1)
    int count = -1;
    ERROR_CHECK(instance->getStringCount(&count));
    return count;
}

int Fmod::getBankVCACount(String pathToBank) {
    DRIVE_PATH(pathToBank)
    FIND_AND_CHECK(pathToBank, banks, -1)
    int count = -1;
    ERROR_CHECK(instance->getVCACount(&count));
    return count;
}

const uint64_t Fmod::createEventInstance(String eventPath) {
    FMOD::Studio::EventInstance *instance = createInstance(eventPath, false, nullptr);
    if (instance) {
        return (uint64_t) instance;
    }
    return 0;
}

float Fmod::getEventParameterByName(uint64_t instanceId, String parameterName) {
    float p = -1;
    FIND_AND_CHECK(instanceId, events, p)
    ERROR_CHECK(instance->getParameterByName(parameterName.utf8().get_data(), &p));
    return p;
}

void Fmod::setEventParameterByName(const uint64_t instanceId, String parameterName, float value) {
    FIND_AND_CHECK(instanceId, events)
    ERROR_CHECK(instance->setParameterByName(parameterName.utf8().get_data(), value));
}

float Fmod::getEventParameterByID(const uint64_t instanceId, const Array idPair) {
    float value = -1.0f;
    FIND_AND_CHECK(instanceId, events, value)
    FMOD_STUDIO_PARAMETER_ID id;
    id.data1 = idPair[0];
    id.data2 = idPair[1];
    ERROR_CHECK(instance->getParameterByID(id, &value));
    return value;
}

void Fmod::setEventParameterByID(uint64_t instanceId, const Array idPair, const float value) {
    FIND_AND_CHECK(instanceId, events)
    FMOD_STUDIO_PARAMETER_ID id;
    id.data1 = idPair[0];
    id.data2 = idPair[1];
    ERROR_CHECK(instance->setParameterByID(id, value));
}

void Fmod::releaseEvent(const uint64_t instanceId) {
    FIND_AND_CHECK(instanceId, events)
    releaseOneEvent(instance);
}

void Fmod::releaseOneEvent(FMOD::Studio::EventInstance *eventInstance) {
    std::lock_guard<std::mutex> lk(Callbacks::callback_mut);
    EventInfo *eventInfo = getEventInfo(eventInstance);
    eventInstance->setUserData(nullptr);
    ERROR_CHECK(eventInstance->release());
    events.erase(eventInstance);
    delete eventInfo;
}

void Fmod::startEvent(const uint64_t instanceId) {
    FIND_AND_CHECK(instanceId, events)
    ERROR_CHECK(instance->start());
}

void Fmod::stopEvent(const uint64_t instanceId, int stopMode) {
    FIND_AND_CHECK(instanceId, events)
    ERROR_CHECK(instance->stop(static_cast<FMOD_STUDIO_STOP_MODE>(stopMode)));
}

void Fmod::triggerEventCue(const uint64_t instanceId) {
    FIND_AND_CHECK(instanceId, events)
    ERROR_CHECK(instance->triggerCue());
}

int Fmod::getEventPlaybackState(const uint64_t instanceId) {
    int s = -1;
    FIND_AND_CHECK(instanceId, events, s)
    ERROR_CHECK(instance->getPlaybackState((FMOD_STUDIO_PLAYBACK_STATE *) &s));
    return s;
}

bool Fmod::getEventPaused(const uint64_t instanceId) {
    bool paused = false;
    FIND_AND_CHECK(instanceId, events, paused)
    ERROR_CHECK(instance->getPaused(&paused));
    return paused;
}

void Fmod::setEventPaused(const uint64_t instanceId, bool paused) {
    FIND_AND_CHECK(instanceId, events)
    ERROR_CHECK(instance->setPaused(paused));
}

float Fmod::getEventPitch(const uint64_t instanceId) {
    float pitch = 0.0f;
    FIND_AND_CHECK(instanceId, events, pitch)
    ERROR_CHECK(instance->getPitch(&pitch));
    return pitch;
}

void Fmod::setEventPitch(const uint64_t instanceId, float pitch) {
    FIND_AND_CHECK(instanceId, events)
    ERROR_CHECK(instance->setPitch(pitch));
}

float Fmod::getEventVolume(const uint64_t instanceId) {
    float volume = 0.0f;
    FIND_AND_CHECK(instanceId, events, volume)
    ERROR_CHECK(instance->getVolume(&volume));
    return volume;
}

void Fmod::setEventVolume(const uint64_t instanceId, float volume) {
    FIND_AND_CHECK(instanceId, events)
    ERROR_CHECK(instance->setVolume(volume));
}

int Fmod::getEventTimelinePosition(const uint64_t instanceId) {
    int tp = 0;
    FIND_AND_CHECK(instanceId, events, tp)
    ERROR_CHECK(instance->getTimelinePosition(&tp));
    return tp;
}

void Fmod::setEventTimelinePosition(const uint64_t instanceId, int position) {
    FIND_AND_CHECK(instanceId, events)
    ERROR_CHECK(instance->setTimelinePosition(position));
}

float Fmod::getEventReverbLevel(const uint64_t instanceId, int index) {
    float rvl = 0.0f;
    FIND_AND_CHECK(instanceId, events, rvl)
    ERROR_CHECK(instance->getReverbLevel(index, &rvl));
    return rvl;
}

void Fmod::setEventReverbLevel(const uint64_t instanceId, int index, float level) {
    FIND_AND_CHECK(instanceId, events)
    ERROR_CHECK(instance->setReverbLevel(index, level));
}

bool Fmod::isEventVirtual(const uint64_t instanceId) {
    bool v = false;
    FIND_AND_CHECK(instanceId, events, v)
    ERROR_CHECK(instance->isVirtual(&v));
    return v;
}

void Fmod::setEventListenerMask(uint64_t instanceId, unsigned int mask) {
    FIND_AND_CHECK(instanceId, events)
    ERROR_CHECK(instance->setListenerMask(mask));
}

uint32_t Fmod::getEventListenerMask(uint64_t instanceId) {
    uint32_t mask = 0;
    FIND_AND_CHECK(instanceId, events, mask)
    ERROR_CHECK(instance->getListenerMask(&mask));
    return mask;
}

void Fmod::setEvent2DAttributes(const uint64_t instanceId, const Transform2D position) {
    FIND_AND_CHECK(instanceId, events)
    auto attr = get3DAttributesFromTransform2D(position);
    ERROR_CHECK(instance->set3DAttributes(&attr));
}

Dictionary Fmod::getEvent2DAttributes(const uint64_t instanceId) {
    Dictionary _2Dattr;
    FIND_AND_CHECK(instanceId, events, _2Dattr)
    FMOD_3D_ATTRIBUTES
            attr;
    ERROR_CHECK(instance->get3DAttributes(&attr));
    _2Dattr = getTransform2DInfoFrom3DAttribut(attr);
    return _2Dattr;
}

void Fmod::setEvent3DAttributes(const uint64_t instanceId, const Transform transform) {
    FIND_AND_CHECK(instanceId, events)
    auto attr = get3DAttributesFromTransform(transform);
    ERROR_CHECK(instance->set3DAttributes(&attr));
}

Dictionary Fmod::getEvent3DAttributes(const uint64_t instanceId) {
    Dictionary _3Dattr;
    FIND_AND_CHECK(instanceId, events, _3Dattr)
    FMOD_3D_ATTRIBUTES
            attr;
    ERROR_CHECK(instance->get3DAttributes(&attr));
    _3Dattr = getTransformInfoFrom3DAttribut(attr);
    return _3Dattr;
}

int Fmod::descGetLength(const String eventPath) {
    int length = -1;
    FIND_AND_CHECK(eventPath, eventDescriptions, length);
    ERROR_CHECK(instance->getLength(&length));
    return length;
}

Array Fmod::descGetInstanceList(const String eventPath) {
    Array array;
    FIND_AND_CHECK(eventPath, eventDescriptions, array)
    FMOD::Studio::EventInstance *instances[MAX_EVENT_INSTANCE];
    int count = 0;
    ERROR_CHECK(instance->getInstanceList(instances, MAX_EVENT_INSTANCE, &count));
    CHECK_SIZE(MAX_EVENT_INSTANCE, count, events)
    for (int i = 0; i < count; i++) {
        array.append((uint64_t) instances[i]);
    }
    return array;
}

int Fmod::descGetInstanceCount(const String eventPath) {
    int count = -1;
    FIND_AND_CHECK(eventPath, eventDescriptions, count)
    ERROR_CHECK(instance->getInstanceCount(&count));
    return count;
}

void Fmod::descReleaseAllInstances(const String eventPath) {
    std::lock_guard<std::mutex> lk(Callbacks::callback_mut);
    FIND_AND_CHECK(eventPath, eventDescriptions)
    FMOD::Studio::EventInstance *instances[MAX_EVENT_INSTANCE];
    int count = 0;
    ERROR_CHECK(instance->getInstanceList(instances, MAX_EVENT_INSTANCE, &count));
    CHECK_SIZE(MAX_EVENT_INSTANCE, count, events)
    for (int i = 0; i < count; i++) {
        FMOD::Studio::EventInstance *it = instances[i];
        if (events.has(it)) {
            EventInfo *eventInfo = getEventInfo(it);
            it->setUserData(nullptr);
            events.erase(it);
            delete eventInfo;
        }
    }
    ERROR_CHECK(instance->releaseAllInstances());
}

void Fmod::descLoadSampleData(const String eventPath) {
    FIND_AND_CHECK(eventPath, eventDescriptions)
    ERROR_CHECK(instance->loadSampleData());
}

void Fmod::descUnloadSampleData(const String eventPath) {
    FIND_AND_CHECK(eventPath, eventDescriptions)
    ERROR_CHECK(instance->unloadSampleData());
}

int Fmod::descGetSampleLoadingState(const String eventPath) {
    FIND_AND_CHECK(eventPath, eventDescriptions, -1)
    FMOD_STUDIO_LOADING_STATE s;
    ERROR_CHECK(instance->getSampleLoadingState(&s));
    return s;
}

bool Fmod::descIs3D(const String eventPath) {
    bool is3D = false;
    FIND_AND_CHECK(eventPath, eventDescriptions, is3D)
    ERROR_CHECK(instance->is3D(&is3D));
    return is3D;
}

bool Fmod::descIsOneShot(const String eventPath) {
    bool isOneShot = false;
    FIND_AND_CHECK(eventPath, eventDescriptions, isOneShot)
    ERROR_CHECK(instance->isOneshot(&isOneShot));
    return isOneShot;
}

bool Fmod::descIsSnapshot(const String eventPath) {
    bool isSnapshot = false;
    FIND_AND_CHECK(eventPath, eventDescriptions, isSnapshot)
    ERROR_CHECK(instance->isSnapshot(&isSnapshot));
    return isSnapshot;
}

bool Fmod::descIsStream(const String eventPath) {
    bool isStream = false;
    FIND_AND_CHECK(eventPath, eventDescriptions, isStream)
    ERROR_CHECK(instance->isStream(&isStream));
    return isStream;
}

bool Fmod::descHasCue(const String eventPath) {
    bool hasCue = false;
    FIND_AND_CHECK(eventPath, eventDescriptions, hasCue)
    ERROR_CHECK(instance->hasCue(&hasCue));
    return hasCue;
}

float Fmod::descGetMaximumDistance(const String eventPath) {
    float distance = 0.f;
    FIND_AND_CHECK(eventPath, eventDescriptions, distance)
    ERROR_CHECK(instance->getMaximumDistance(&distance));
    return distance;
}

float Fmod::descGetMinimumDistance(const String eventPath) {
    float distance = 0.f;
    FIND_AND_CHECK(eventPath, eventDescriptions, distance)
    ERROR_CHECK(instance->getMinimumDistance(&distance));
    return distance;
}

float Fmod::descGetSoundSize(const String eventPath) {
    float soundSize = 0.f;
    FIND_AND_CHECK(eventPath, eventDescriptions, soundSize)
    ERROR_CHECK(instance->getSoundSize(&soundSize));
    return soundSize;
}

Dictionary Fmod::descGetParameterDescriptionByName(const String eventPath, const String name) {
    Dictionary paramDesc;
    FIND_AND_CHECK(eventPath, eventDescriptions, paramDesc)
    FMOD_STUDIO_PARAMETER_DESCRIPTION
            pDesc;
    if (ERROR_CHECK(instance->getParameterDescriptionByName(name.utf8().get_data(), &pDesc))) {
        paramDesc["name"] = String(pDesc.name);
        paramDesc["id_first"] = pDesc.id.data1;
        paramDesc["id_second"] = pDesc.id.data2;
        paramDesc["minimum"] = pDesc.minimum;
        paramDesc["maximum"] = pDesc.maximum;
        paramDesc["default_value"] = pDesc.defaultvalue;
    }
    return paramDesc;
}

Dictionary Fmod::descGetParameterDescriptionByID(const String eventPath, const Array idPair) {
    Dictionary paramDesc;
    FIND_AND_CHECK(eventPath, eventDescriptions, paramDesc)
    FMOD_STUDIO_PARAMETER_ID paramId;
    paramId.data1 = (unsigned int) idPair[0];
    paramId.data2 = (unsigned int) idPair[1];
    FMOD_STUDIO_PARAMETER_DESCRIPTION
            pDesc;
    if (ERROR_CHECK(instance->getParameterDescriptionByID(paramId, &pDesc))) {
        paramDesc["name"] = String(pDesc.name);
        paramDesc["id_first"] = pDesc.id.data1;
        paramDesc["id_second"] = pDesc.id.data2;
        paramDesc["minimum"] = pDesc.minimum;
        paramDesc["maximum"] = pDesc.maximum;
        paramDesc["default_value"] = pDesc.defaultvalue;
    }
    return paramDesc;
}

int Fmod::descGetParameterDescriptionCount(const String eventPath) {
    int count = 0;
    FIND_AND_CHECK(eventPath, eventDescriptions, count)
    ERROR_CHECK(instance->getParameterDescriptionCount(&count));
    return count;
}

Dictionary Fmod::descGetParameterDescriptionByIndex(const String eventPath, const int index) {
    Dictionary paramDesc;
    FIND_AND_CHECK(eventPath, eventDescriptions, paramDesc)
    FMOD_STUDIO_PARAMETER_DESCRIPTION
            pDesc;
    if (ERROR_CHECK(instance->getParameterDescriptionByIndex(index, &pDesc))) {
        paramDesc["name"] = String(pDesc.name);
        paramDesc["id_first"] = pDesc.id.data1;
        paramDesc["id_second"] = pDesc.id.data2;
        paramDesc["minimum"] = pDesc.minimum;
        paramDesc["maximum"] = pDesc.maximum;
        paramDesc["default_value"] = pDesc.defaultvalue;
    }
    return paramDesc;
}

Dictionary Fmod::descGetUserProperty(const String eventPath, const String name) {
    Dictionary propDesc;
    FIND_AND_CHECK(eventPath, eventDescriptions, propDesc)
    FMOD_STUDIO_USER_PROPERTY
            uProp;
    if (ERROR_CHECK(instance->getUserProperty(name.utf8().get_data(), &uProp))) {
        FMOD_STUDIO_USER_PROPERTY_TYPE fType = uProp.type;
        if (fType == FMOD_STUDIO_USER_PROPERTY_TYPE_INTEGER)
            propDesc[String(uProp.name)] = uProp.intvalue;
        else if (fType == FMOD_STUDIO_USER_PROPERTY_TYPE_BOOLEAN)
            propDesc[String(uProp.name)] = (bool) uProp.boolvalue;
        else if (fType == FMOD_STUDIO_USER_PROPERTY_TYPE_FLOAT)
            propDesc[String(uProp.name)] = uProp.floatvalue;
        else if (fType == FMOD_STUDIO_USER_PROPERTY_TYPE_STRING)
            propDesc[String(uProp.name)] = String(uProp.stringvalue);
    }
    return propDesc;
}

int Fmod::descGetUserPropertyCount(const String eventPath) {
    int count = 0;
    FIND_AND_CHECK(eventPath, eventDescriptions, count)
    ERROR_CHECK(instance->getUserPropertyCount(&count));
    return count;
}

Dictionary Fmod::descUserPropertyByIndex(const String eventPath, const int index) {
    Dictionary propDesc;
    FIND_AND_CHECK(eventPath, eventDescriptions, propDesc)
    FMOD_STUDIO_USER_PROPERTY
            uProp;
    if (ERROR_CHECK(instance->getUserPropertyByIndex(index, &uProp))) {
        FMOD_STUDIO_USER_PROPERTY_TYPE fType = uProp.type;
        if (fType == FMOD_STUDIO_USER_PROPERTY_TYPE_INTEGER)
            propDesc[String(uProp.name)] = uProp.intvalue;
        else if (fType == FMOD_STUDIO_USER_PROPERTY_TYPE_BOOLEAN)
            propDesc[String(uProp.name)] = (bool) uProp.boolvalue;
        else if (fType == FMOD_STUDIO_USER_PROPERTY_TYPE_FLOAT)
            propDesc[String(uProp.name)] = uProp.floatvalue;
        else if (fType == FMOD_STUDIO_USER_PROPERTY_TYPE_STRING)
            propDesc[String(uProp.name)] = String(uProp.stringvalue);
    }

    return propDesc;
}

bool Fmod::getBusMute(const String busPath) {
    bool mute = false;
    FIND_AND_CHECK(busPath, buses, mute)
    ERROR_CHECK(instance->getMute(&mute));
    return mute;
}

bool Fmod::getBusPaused(const String busPath) {
    bool paused = false;
    FIND_AND_CHECK(busPath, buses, paused)
    ERROR_CHECK(instance->getPaused(&paused));
    return paused;
}

float Fmod::getBusVolume(const String busPath) {
    float volume = 0.0f;
    FIND_AND_CHECK(busPath, buses, volume)
    ERROR_CHECK(instance->getVolume(&volume));
    return volume;
}

void Fmod::setBusMute(const String busPath, bool mute) {
    FIND_AND_CHECK(busPath, buses)
    ERROR_CHECK(instance->setMute(mute));
}

void Fmod::setBusPaused(const String busPath, bool paused) {
    FIND_AND_CHECK(busPath, buses)
    ERROR_CHECK(instance->setPaused(paused));
}

void Fmod::setBusVolume(const String busPath, float volume) {
    FIND_AND_CHECK(busPath, buses)
    ERROR_CHECK(instance->setVolume(volume));
}

void Fmod::stopAllBusEvents(const String busPath, int stopMode) {
    FIND_AND_CHECK(busPath, buses)
    ERROR_CHECK(instance->stopAllEvents(static_cast<FMOD_STUDIO_STOP_MODE>(stopMode)));
}

void Fmod::loadBankData(LoadingBank *loadingBank) {
    char path[MAX_PATH_SIZE];
    auto bank = loadingBank->bank;
    FMOD_RESULT result = bank->getPath(path, MAX_PATH_SIZE, nullptr);
    if (result == FMOD_OK) {
        GODOT_LOG(0, "FMOD Sound System: BANK " + String(path) + " LOADED")
        loadAllBuses(bank);
        loadAllVCAs(bank);
        loadAllEventDescriptions(bank);
        banks[loadingBank->godotPath] << bank;
    } else {
        if (result == FMOD_ERR_EVENT_NOTFOUND) {
            GODOT_LOG(0, "FMOD Sound System: BANK " + String(path) +
                         " COULDN'T BE LOADED. Path incorrect or MasterBank not loaded yet.")
        } else {
            ERROR_CHECK(result);
        }
        bank->unload();
    }
}

void Fmod::loadAllVCAs(FMOD::Studio::Bank *bank) {
    FMOD::Studio::VCA *array[MAX_VCA_COUNT];
    int size = 0;
    if (ERROR_CHECK(bank->getVCAList(array, MAX_VCA_COUNT, &size))) {
        CHECK_SIZE(MAX_VCA_COUNT, size, VCAs)
        for (int i = 0; i < size; i++) {
            auto vca = array[i];
            char path[MAX_PATH_SIZE];
            ERROR_CHECK(vca->getPath(path, MAX_PATH_SIZE, nullptr));
            GODOT_LOG(0, "FMOD Sound System: " + String(path) + " added to VCAs")
            VCAs[path] << vca;
        }
    }
}

void Fmod::loadAllBuses(FMOD::Studio::Bank *bank) {
    FMOD::Studio::Bus *array[MAX_BUS_COUNT];
    int size = 0;
    if (ERROR_CHECK(bank->getBusList(array, MAX_BUS_COUNT, &size))) {
        CHECK_SIZE(MAX_BUS_COUNT, size, buses)
        for (int i = 0; i < size; i++) {
            auto bus = array[i];
            char path[MAX_PATH_SIZE];
            ERROR_CHECK(bus->getPath(path, MAX_PATH_SIZE, nullptr));
            GODOT_LOG(0, "FMOD Sound System: " + String(path) + " added to buses")
            buses[path] << bus;
        }
    }
}

void Fmod::loadAllEventDescriptions(FMOD::Studio::Bank *bank) {
    FMOD::Studio::EventDescription *array[MAX_EVENT_COUNT];
    int size = 0;
    if (ERROR_CHECK(bank->getEventList(array, MAX_EVENT_COUNT, &size))) {
        CHECK_SIZE(MAX_EVENT_COUNT, size, Events)
        for (int i = 0; i < size; i++) {
            auto eventDescription = array[i];
            char path[MAX_PATH_SIZE];
            ERROR_CHECK(eventDescription->getPath(path, MAX_PATH_SIZE, nullptr));
            GODOT_LOG(0, "FMOD Sound System: " + String(path) + " added to eventDescriptions")
            eventDescriptions[path] << eventDescription;
        }
    }
}

void Fmod::unloadAllVCAs(FMOD::Studio::Bank *bank) {
    FMOD::Studio::VCA *array[MAX_VCA_COUNT];
    int size = 0;
    if (ERROR_CHECK(bank->getVCAList(array, MAX_VCA_COUNT, &size))) {
        CHECK_SIZE(MAX_VCA_COUNT, size, VCAs)
        for (int i = 0; i < size; i++) {
            auto vca = array[i];
            char path[MAX_PATH_SIZE];
            ERROR_CHECK(vca->getPath(path, MAX_PATH_SIZE, nullptr));
            GODOT_LOG(0, "FMOD Sound System: " + String(path) + " removed from VCAs")
            VCAs.erase(path);
        }
    }
}

void Fmod::unloadAllBuses(FMOD::Studio::Bank *bank) {
    FMOD::Studio::Bus *array[MAX_BUS_COUNT];
    int size = 0;
    if (ERROR_CHECK(bank->getBusList(array, MAX_BUS_COUNT, &size))) {
        CHECK_SIZE(MAX_BUS_COUNT, size, buses)
        for (int i = 0; i < size; i++) {
            auto bus = array[i];
            char path[MAX_PATH_SIZE];
            ERROR_CHECK(bus->getPath(path, MAX_PATH_SIZE, nullptr));
            GODOT_LOG(0, "FMOD Sound System: " + String(path) + " removed from buses")
            buses.erase(path);
        }
    }
}

void Fmod::unloadAllEventDescriptions(FMOD::Studio::Bank *bank) {
    FMOD::Studio::EventDescription *array[MAX_EVENT_COUNT];
    int size = 0;
    if (ERROR_CHECK(bank->getEventList(array, MAX_EVENT_COUNT, &size))) {
        CHECK_SIZE(MAX_EVENT_COUNT, size, Events)
        for (int i = 0; i < size; i++) {
            auto eventDescription = array[i];
            char path[MAX_PATH_SIZE];
            ERROR_CHECK(eventDescription->getPath(path, MAX_PATH_SIZE, nullptr));
            GODOT_LOG(0, "FMOD Sound System: " + String(path) + " removed from eventDescriptions")
            eventDescriptions.erase(path);
        }
    }
}

bool Fmod::checkVCAPath(const String vcaPath) {
    return VCAs.has(vcaPath);
}

bool Fmod::checkBusPath(const String busPath) {
    return buses.has(busPath);
}

bool Fmod::checkEventPath(const String eventPath) {
    return eventDescriptions.has(eventPath);
}

FMOD::Studio::EventInstance *Fmod::createInstance(String eventName, bool isOneShot, Node *gameObject) {
    FIND_AND_CHECK(eventName, eventDescriptions, nullptr)
    FMOD::Studio::EventInstance *eventInstance = nullptr;
    ERROR_CHECK(instance->createInstance(&eventInstance));
    if (eventInstance && (!isOneShot || gameObject)) {
        auto *eventInfo = new EventInfo();
        eventInfo->gameObj = gameObject;
        eventInfo->isOneShot = isOneShot;
        eventInstance->setUserData(eventInfo);
        events.append(eventInstance);
    }
    return eventInstance;
}

EventInfo *Fmod::getEventInfo(FMOD::Studio::EventInstance *eventInstance) {
    EventInfo *eventInfo;
    ERROR_CHECK(eventInstance->getUserData((void **) &eventInfo));
    return eventInfo;
}

void Fmod::playOneShot(String eventName, Node *gameObj) {
    FMOD::Studio::EventInstance *instance = createInstance(eventName, true, nullptr);
    if (instance) {
        // set 3D attributes once
        if (isFmodValid(gameObj)) {
            updateInstance3DAttributes(instance, gameObj);
        }
        ERROR_CHECK(instance->start());
        ERROR_CHECK(instance->release());
    }
}

void Fmod::playOneShotWithParams(String eventName, Node *gameObj, Dictionary parameters) {
    FMOD::Studio::EventInstance *instance = createInstance(eventName, true, nullptr);
    if (instance) {
        // set 3D attributes once
        if (isFmodValid(gameObj)) {
            updateInstance3DAttributes(instance, gameObj);
        }
        // set the initial parameter values
        auto keys = parameters.keys();
        for (int i = 0; i < keys.size(); i++) {
            String k = keys[i];
            float v = parameters[keys[i]];
            ERROR_CHECK(instance->setParameterByName(k.utf8().get_data(), v));
        }
        ERROR_CHECK(instance->start());
        ERROR_CHECK(instance->release());
    }
}

void Fmod::playOneShotAttached(String eventName, Node *gameObj) {
    if (isFmodValid(gameObj)) {
        FMOD::Studio::EventInstance *instance = createInstance(eventName, true, gameObj);
        if (instance) {
            ERROR_CHECK(instance->start());
        }
    }
}

void Fmod::playOneShotAttachedWithParams(String eventName, Node *gameObj, Dictionary parameters) {
    if (isFmodValid(gameObj)) {
        FMOD::Studio::EventInstance *instance = createInstance(eventName, true, gameObj);
        if (instance) {
            // set the initial parameter values
            auto keys = parameters.keys();
            for (int i = 0; i < keys.size(); i++) {
                String k = keys[i];
                float v = parameters[keys[i]];
                ERROR_CHECK(instance->setParameterByName(k.utf8().get_data(), v));
            }
            ERROR_CHECK(instance->start());
        }
    }
}

void Fmod::attachInstanceToNode(uint64_t instanceId, Node *gameObj) {
    if (!isFmodValid(gameObj)) {
        GODOT_LOG(1, "Trying to attach event instance to null game object or object is not Spatial or CanvasItem")
        return;
    }
    FIND_AND_CHECK(instanceId, events)
    getEventInfo(instance)->gameObj = gameObj;
}

void Fmod::detachInstanceFromNode(const uint64_t instanceId) {
    FIND_AND_CHECK(instanceId, events)
    getEventInfo(instance)->gameObj = nullptr;
}

Node * Fmod::getObjectAttachedToInstance(uint64_t instanceId) {
    Node *node = nullptr;
    FIND_AND_CHECK(instanceId, events, node)
    EventInfo *eventInfo = getEventInfo(instance);
    if (eventInfo) {
        node = eventInfo->gameObj;
        if (!node) {
            GODOT_LOG(1, "There is no node attached to event instance.")
        }
    }
    return node;
}

void Fmod::pauseAllEvents(const bool pause) {
    for (int i = 0; i < events.size(); i++) {
        auto eventInstance = events.get(i);
        if (eventInstance) {
            ERROR_CHECK(eventInstance->setPaused(pause));
        }
    }
}

void Fmod::muteAllEvents() {
    if (banks.size() > 1) {
        FMOD::Studio::Bus *masterBus = nullptr;
        if (ERROR_CHECK(system->getBus("bus:/", &masterBus))) {
            masterBus->setMute(true);
        }
    }
}

void Fmod::unmuteAllEvents() {
    if (banks.size() > 1) {
        FMOD::Studio::Bus *masterBus = nullptr;
        if (ERROR_CHECK(system->getBus("bus:/", &masterBus))) {
            masterBus->setMute(false);
        }
    }
}

bool Fmod::banksStillLoading() {
    for (int i = 0; i < banks.size(); i++) {
        FMOD::Studio::Bank *bank = banks.get(i);
        FMOD_STUDIO_LOADING_STATE loadingState;
        ERROR_CHECK(bank->getLoadingState(&loadingState));
        if (loadingState == FMOD_STUDIO_LOADING_STATE_LOADING) {
            return true;
        }
    }
    return false;
}

float Fmod::getVCAVolume(const String VCAPath) {
    float volume = 0.0f;
    FIND_AND_CHECK(VCAPath, VCAs, volume)
    ERROR_CHECK(instance->getVolume(&volume));
    return volume;
}

void Fmod::setVCAVolume(const String VCAPath, float volume) {
    FIND_AND_CHECK(VCAPath, VCAs)
    ERROR_CHECK(instance->setVolume(volume));
}

void Fmod::loadFileAsSound(String path) {
    DRIVE_PATH(path)
    FMOD::Sound *sound = sounds.get(path);
    if (!sound) {
        ERROR_CHECK(coreSystem->createSound(path.alloc_c_string(), FMOD_CREATESAMPLE, nullptr, &sound));
        if (sound) {
            sounds[path] << sound;
            Godot::print("FMOD Sound System: LOADING AS SOUND FILE" + String(path));
        }
    }
}

void Fmod::loadFileAsMusic(String path) {
    DRIVE_PATH(path)
    FMOD::Sound *sound = sounds.get(path);
    if (!sound) {
        ERROR_CHECK(coreSystem->createSound(path.alloc_c_string(), (FMOD_CREATESTREAM | FMOD_LOOP_NORMAL) , nullptr, &sound));
        if (sound) {
            sounds[path] << sound;
            Godot::print("FMOD Sound System: LOADING AS MUSIC FILE" + String(path));
        }
    }
}

void Fmod::unloadFile(String path) {
    DRIVE_PATH(path)
    FIND_AND_CHECK(path, sounds)
    ERROR_CHECK(instance->release());
    sounds.erase(path);
    Godot::print("FMOD Sound System: UNLOADING FILE" + String(path));
}

const uint64_t Fmod::createSoundInstance(String path) {
    DRIVE_PATH(path)
    FIND_AND_CHECK(path, sounds, 0)
    FMOD::Channel *channel = nullptr;
    ERROR_CHECK(coreSystem->playSound(instance, nullptr, true, &channel));
    if (channel) {
        channels.append(channel);
        return (uint64_t) channel;
    }
    return 0;
}

bool Fmod::checkSoundInstance(const uint64_t instanceId) {
    FIND_AND_CHECK(instanceId, channels, false)
    return isChannelValid(instance);
}

bool Fmod::isChannelValid(FMOD::Channel *channel) {
    bool isPlaying;
    FMOD_RESULT result = channel->isPlaying(&isPlaying);
    return result != FMOD_ERR_INVALID_HANDLE;
}

void Fmod::releaseSound(const uint64_t  instanceId){
    FIND_AND_CHECK(instanceId, channels)
    ERROR_CHECK(instance->stop());
    channels.erase(instance);
}

void Fmod::playSound(const uint64_t instanceId) {
    FIND_AND_CHECK(instanceId, channels)
    setSoundPaused(instanceId, false);
}

void Fmod::setSoundPaused(const uint64_t instanceId, bool paused) {
    FIND_AND_CHECK(instanceId, channels)
    ERROR_CHECK(instance->setPaused(paused));
}

void Fmod::stopSound(const uint64_t instanceId) {
    FIND_AND_CHECK(instanceId, channels)
    ERROR_CHECK(instance->stop());
}

bool Fmod::isSoundPlaying(const uint64_t instanceId) {
    bool isPlaying = false;
    FIND_AND_CHECK(instanceId, channels, isPlaying)
    ERROR_CHECK(instance->isPlaying(&isPlaying));
    return isPlaying;
}

void Fmod::setSoundVolume(const uint64_t instanceId, float volume) {
    FIND_AND_CHECK(instanceId, channels)
    ERROR_CHECK(instance->setVolume(volume));
}

float Fmod::getSoundVolume(const uint64_t instanceId) {
    float volume = 0.f;
    FIND_AND_CHECK(instanceId, channels, volume)
    ERROR_CHECK(instance->getVolume(&volume));
    return volume;
}

float Fmod::getSoundPitch(const uint64_t instanceId) {
    float pitch = 0.f;
    FIND_AND_CHECK(instanceId, channels, pitch)
    ERROR_CHECK(instance->getPitch(&pitch));
    return pitch;
}

void Fmod::setSoundPitch(const uint64_t instanceId, float pitch) {
    FIND_AND_CHECK(instanceId, channels)
    ERROR_CHECK(instance->setPitch(pitch));
}

void Fmod::setSound3DSettings(float dopplerScale, float distanceFactor, float rollOffScale) {
    if (distanceFactor > 0 && ERROR_CHECK(coreSystem->set3DSettings(dopplerScale, distanceFactor, rollOffScale))) {
        distanceScale = distanceFactor;
        GODOT_LOG(0, "FMOD Sound System: Successfully set global 3D settings")
    } else {
        GODOT_LOG(2, "FMOD Sound System: Failed to set 3D settings :|")
    }
}

void Fmod::waitForAllLoads() {
    ERROR_CHECK(system->flushSampleLoading());
    checkLoadingBanks();
}

Array Fmod::getAvailableDrivers() {
    Array driverList;
    int numDrivers = 0;

    ERROR_CHECK(coreSystem->getNumDrivers(&numDrivers));

    for (int i = 0; i < numDrivers; i++) {
        char name[MAX_DRIVER_NAME_SIZE];
        int sampleRate;
        FMOD_SPEAKERMODE speakerMode;
        int speakerModeChannels;
        ERROR_CHECK(coreSystem->getDriverInfo(i, name, MAX_DRIVER_NAME_SIZE, nullptr, &sampleRate, &speakerMode,
                                              &speakerModeChannels));
        String nameStr(name);

        Dictionary driverInfo;
        driverInfo["id"] = i;
        driverInfo["name"] = nameStr;
        driverInfo["sample_rate"] = sampleRate;
        driverInfo["speaker_mode"] = (int) speakerMode;
        driverInfo["number_of_channels"] = speakerModeChannels;
        driverList.push_back(driverInfo);
    }

    return driverList;
}

int Fmod::getDriver() {
    int driverId = -1;
    ERROR_CHECK(coreSystem->getDriver(&driverId));
    return driverId;
}

void Fmod::setDriver(const int id) {
    ERROR_CHECK(coreSystem->setDriver(id));
}

Dictionary Fmod::getPerformanceData() {

    // get the CPU usage
    FMOD_STUDIO_CPU_USAGE cpuUsage;
    ERROR_CHECK(system->getCPUUsage(&cpuUsage));
    Dictionary cpuPerfData = performanceData["CPU"];
    cpuPerfData["dsp"] = cpuUsage.dspusage;
    cpuPerfData["geometry"] = cpuUsage.geometryusage;
    cpuPerfData["stream"] = cpuUsage.streamusage;
    cpuPerfData["studio"] = cpuUsage.studiousage;
    cpuPerfData["update"] = cpuUsage.updateusage;

    // get the memory usage
    int currentAlloc = 0;
    int maxAlloc = 0;
    ERROR_CHECK(FMOD::Memory_GetStats(&currentAlloc, &maxAlloc));
    Dictionary memPerfData = performanceData["memory"];
    memPerfData["currently_allocated"] = currentAlloc;
    memPerfData["max_allocated"] = maxAlloc;

    // get the file usage
    long long sampleBytesRead = 0;
    long long streamBytesRead = 0;
    long long otherBytesRead = 0;
    ERROR_CHECK(coreSystem->getFileUsage(&sampleBytesRead, &streamBytesRead, &otherBytesRead));
    Dictionary filePerfData = performanceData["file"];
    filePerfData["sample_bytes_read"] = static_cast<int64_t >(sampleBytesRead);
    filePerfData["stream_bytes_read"] = static_cast<int64_t >(streamBytesRead);
    filePerfData["other_bytes_read"] = static_cast<int64_t >(otherBytesRead);

    return performanceData;
}

void Fmod::setGlobalParameterByName(const String parameterName, float value) {
    ERROR_CHECK(system->setParameterByName(parameterName.utf8().get_data(), value));
}

float Fmod::getGlobalParameterByName(String parameterName) {
    float value = 0.f;
    ERROR_CHECK(system->getParameterByName(parameterName.utf8().get_data(), &value));
    return value;
}

void Fmod::setGlobalParameterByID(const Array idPair, const float value) {
    if (idPair.size() != 2) {
        GODOT_LOG(2, "FMOD Sound System: Invalid parameter ID");
        return;
    }
    FMOD_STUDIO_PARAMETER_ID id;
    id.data1 = idPair[0];
    id.data2 = idPair[1];
    ERROR_CHECK(system->setParameterByID(id, value));
}

float Fmod::getGlobalParameterByID(const Array idPair) {
    if (idPair.size() != 2) {
        GODOT_LOG(2, "FMOD Sound System: Invalid parameter ID");
        return -1.f;
    }
    FMOD_STUDIO_PARAMETER_ID id;
    id.data1 = idPair[0];
    id.data2 = idPair[1];
    float value = -1.f;
    ERROR_CHECK(system->getParameterByID(id, &value));
    return value;
}

Dictionary Fmod::getGlobalParameterDescByName(const String parameterName) {
    Dictionary paramDesc;
    FMOD_STUDIO_PARAMETER_DESCRIPTION
            pDesc;
    if (ERROR_CHECK(system->getParameterDescriptionByName(parameterName.utf8().get_data(), &pDesc))) {
        paramDesc["name"] = String(pDesc.name);
        paramDesc["id_first"] = pDesc.id.data1;
        paramDesc["id_second"] = pDesc.id.data2;
        paramDesc["minimum"] = pDesc.minimum;
        paramDesc["maximum"] = pDesc.maximum;
        paramDesc["default_value"] = pDesc.defaultvalue;
    }

    return paramDesc;
}

Dictionary Fmod::getGlobalParameterDescByID(const Array idPair) {
    if (idPair.size() != 2) {
        GODOT_LOG(2, "FMOD Sound System: Invalid parameter ID");
        return Dictionary();
    }
    Dictionary paramDesc;
    FMOD_STUDIO_PARAMETER_ID id;
    id.data1 = idPair[0];
    id.data2 = idPair[1];
    FMOD_STUDIO_PARAMETER_DESCRIPTION
            pDesc;
    if (ERROR_CHECK(system->getParameterDescriptionByID(id, &pDesc))) {
        paramDesc["name"] = String(pDesc.name);
        paramDesc["id_first"] = pDesc.id.data1;
        paramDesc["id_second"] = pDesc.id.data2;
        paramDesc["minimum"] = pDesc.minimum;
        paramDesc["maximum"] = pDesc.maximum;
        paramDesc["default_value"] = pDesc.defaultvalue;
    }

    return paramDesc;
}

int Fmod::getGlobalParameterDescCount() {
    int count = 0;
    ERROR_CHECK(system->getParameterDescriptionCount(&count));
    return count;
}

Array Fmod::getGlobalParameterDescList() {
    Array a;
    FMOD_STUDIO_PARAMETER_DESCRIPTION
            descList[256];
    int count = 0;
    ERROR_CHECK(system->getParameterDescriptionList(descList, 256, &count));
    for (int i = 0; i < count; i++) {
        auto pDesc = descList[i];
        Dictionary paramDesc;
        paramDesc["name"] = String(pDesc.name);
        paramDesc["id_first"] = pDesc.id.data1;
        paramDesc["id_second"] = pDesc.id.data2;
        paramDesc["minimum"] = pDesc.minimum;
        paramDesc["maximum"] = pDesc.maximum;
        paramDesc["default_value"] = pDesc.defaultvalue;
        a.append(paramDesc);
    }
    return a;
}

void Fmod::setCallback(const uint64_t instanceId, int callbackMask) {
    FIND_AND_CHECK(instanceId, events)
    ERROR_CHECK(instance->setCallback(Callbacks::eventCallback, callbackMask));
    GODOT_LOG(0, String("CallBack set on event ") + String::num(instanceId, 0))
}



// runs on the game thread
void Fmod::runCallbacks() {
    std::lock_guard<std::mutex> lk(Callbacks::callback_mut);
    for (int i = 0; i < events.size(); i++) {
        FMOD::Studio::EventInstance *eventInstance = events.get(i);
        auto eventInfo = getEventInfo(eventInstance);
        if (eventInstance && eventInfo) {
            Callbacks::CallbackInfo *cbInfo = &eventInfo->callbackInfo;
            // check for Marker callbacks
            if (!cbInfo->markerSignalEmitted) {
                emit_signal("timeline_marker", cbInfo->markerCallbackInfo);
                cbInfo->markerSignalEmitted = true;
            }

            // check for Beat callbacks
            if (!cbInfo->beatSignalEmitted) {
                emit_signal("timeline_beat", cbInfo->beatCallbackInfo);
                cbInfo->beatSignalEmitted = true;
            }

            // check for Sound callbacks
            if (!cbInfo->soundSignalEmitted) {
                if (cbInfo->soundCallbackInfo["type"] == String("played"))
                    emit_signal("sound_played", cbInfo->soundCallbackInfo);
                else
                    emit_signal("sound_stopped", cbInfo->soundCallbackInfo);
                cbInfo->soundSignalEmitted = true;
            }
        } else {
            GODOT_LOG(2, "A managed event doesn't have an EventInfoStructure")
        }
    }
}

void Fmod::_init() {
    system = nullptr;
    coreSystem = nullptr;
    isInitialized = false;
    isNotinitPrinted = false;
    Callbacks::GodotFileRunner::get_singleton()->start();
    performanceData["CPU"] = Dictionary();
    performanceData["memory"] = Dictionary();
    performanceData["file"] = Dictionary();
    distanceScale = 1.0;

}
