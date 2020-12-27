#ifndef GODOTFMOD_POINTOBJECT_H
#define GODOTFMOD_POINTOBJECT_H

#endif //GODOTFMOD_POINTOBJECT_H

#include <Godot.hpp>
#include <Object.hpp>


namespace godot{
    class PointObject {

    private:
        enum PointType{
            UNMANAGED = 0,
            CANVAS = 1,
            SPATIAL = 2
        };

        Object* obj = nullptr;
        PointType type = UNMANAGED;

    public:
        explicit PointObject(Object* object) {
            type = UNMANAGED;

            if (!object) {
                Godot::print("Object is null");
                return;
            }

            uint64_t id = object->get_instance_id();
            if(id == 0) {
                Godot::print("Object id is 0");
                return;
            }

            obj = object;
            if(Object::cast_to<CanvasItem>(object)) {
                Godot::print("Object id is CANVAS");
                type = CANVAS;
            }
            else if(Object::cast_to<Spatial>(object)) {
                Godot::print("Object id is SPATIAL");
                type = SPATIAL;
            }
        }
        PointObject() : PointObject(nullptr) {};

        ~PointObject() = default;

        inline bool isValid() const {
            if(type == UNMANAGED) {
                return true;
            }
            return godot::core_1_1_api->godot_is_instance_valid(obj);
        }

        inline CanvasItem* getCanvasItem() const{
            if(type != CANVAS) {
                return nullptr;
            }
            return Object::cast_to<CanvasItem>(obj);
        }

        inline Object* getObject() const{
            if(type == UNMANAGED) {
                return nullptr;
            }
            return obj;
        }

        inline Spatial* getSpatial() const{
            if(type != SPATIAL) {
                return nullptr;
            }
            return Object::cast_to<Spatial>(obj);
        }
    };
}
