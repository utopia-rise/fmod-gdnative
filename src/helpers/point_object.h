#ifndef GODOTFMOD_POINTOBJECT_H
#define GODOTFMOD_POINTOBJECT_H

#endif //GODOTFMOD_POINTOBJECT_H

#include <Godot.hpp>
#include <Object.hpp>


namespace godot{
    class PointObject {

    private:
        enum PointType{
            INVALID = 0,
            CANVAS = 1,
            SPATIAL = 2
        };

        Object* obj = nullptr;
        uint64_t id = 0;
        PointType type = INVALID;

    public:

        PointObject(Object* object) {
            PointType type = INVALID;

            this->id = object->get_instance_id();
            if(id == 0) {
                return;
            }

            obj = object;
            if(Object::cast_to<CanvasItem>(object)) {
                type = CANVAS;
            }
            else if(Object::cast_to<Spatial>(object)) {
                type = SPATIAL;
            }
        }

        ~PointObject() = default;

        inline bool isValid() const {
            uint64_t current_id = obj->get_instance_id();
            if(current_id != id) {
                return false;
            }
            return type != INVALID;
        }

        inline CanvasItem* getCanvasItem() const{
            if(type != CANVAS) {
                return nullptr;
            }
            return Object::cast_to<CanvasItem>(obj);
        }

        inline Object* getObject() const{
            if(type == INVALID) {
                return nullptr;
            }
            return obj;
        }

        inline Spatial* getSpatial() const{
            if(type != SPATIAL) {
                return nullptr;
            }
            return Object::cast_to<CanvasItem>(obj);
        }
    };
}
