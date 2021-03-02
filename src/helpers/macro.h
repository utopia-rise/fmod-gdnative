#ifndef GODOTFMOD_MACRO_H
#define GODOTFMOD_MACRO_H

#define GODOT_LOG(level, message)\
    switch (level) {\
        case 0:\
            godot::Godot::print(message);\
            break;\
        case 1:\
            godot::Godot::print_warning(message, BOOST_CURRENT_FUNCTION, __FILE__, __LINE__);\
            break;\
        case 2:\
            godot::Godot::print_error(message, BOOST_CURRENT_FUNCTION, __FILE__, __LINE__);\
            break;\
    }\

#define FIND_AND_CHECK_WITH_RETURN(instanceId, cont, defaultReturn) \
    auto instance = cont.get(instanceId); \
    if (!instance) { \
        String message = String("FMOD Sound System: cannot find " + String(instanceId) + " in ##cont collection.");\
        GODOT_LOG(2, message)\
        return defaultReturn; \
    }
#define FIND_AND_CHECK_WITHOUT_RETURN(instanceId, set) FIND_AND_CHECK_WITH_RETURN(instanceId, set, void())
#define FUNC_CHOOSER(_f1, _f2, _f3, _f4, ...) _f4
#define FUNC_RECOMPOSER(argsWithParentheses) FUNC_CHOOSER argsWithParentheses
#define MACRO_CHOOSER(...) FUNC_RECOMPOSER((__VA_ARGS__, FIND_AND_CHECK_WITH_RETURN, FIND_AND_CHECK_WITHOUT_RETURN, ))
#define FIND_AND_CHECK(...) MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)

#define CHECK_SIZE(maxSize, actualSize, type) \
    if(actualSize > maxSize){\
        String message = "FMOD Sound System: type maximum size is " + String::num(maxSize) + " but the bank contains " + String::num(actualSize) + " entries";\
        GODOT_LOG(2, message)\
        actualSize = maxSize;\
    }\

#endif //GODOTFMOD_MACRO_H
