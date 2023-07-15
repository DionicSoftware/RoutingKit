#include <unity_logger.h>

LogCallback callbackInstance = nullptr;

ROUTINGKIT_API void register_debug_callback(LogCallback callback) {
    callbackInstance = callback;
    UnityDebug::Log("Registered debug callback from C# to C++");
}

ROUTINGKIT_API void test_debug() {
    UnityDebug::Log("Hello from C++");
}


void UnityDebug::Log(const char* message, LogType type) {
    if (callbackInstance != nullptr)
        callbackInstance(message, (int)type, (int)strlen(message));
}

void UnityDebug::Log(const std::string message, LogType type) {
    const char* tmsg = message.c_str();
    if (callbackInstance != nullptr)
        callbackInstance(tmsg, (int)type, (int)strlen(tmsg));
}

void UnityDebug::Log(const int message, LogType type) {
    std::stringstream ss;
    ss << message;
    send_log(ss, type);
}

void UnityDebug::Log(const char message, LogType type) {
    std::stringstream ss;
    ss << message;
    send_log(ss, type);
}

void UnityDebug::Log(const float message, LogType type) {
    std::stringstream ss;
    ss << message;
    send_log(ss, type);
}

void UnityDebug::Log(const double message, LogType type) {
    std::stringstream ss;
    ss << message;
    send_log(ss, type);
}

void UnityDebug::Log(const bool message, LogType type) {
    std::stringstream ss;
    if (message)
        ss << "true";
    else
        ss << "false";

    send_log(ss, type);
}

void UnityDebug::send_log(const std::stringstream &ss, const LogType &type) {
    const std::string tmp = ss.str();
    const char* tmsg = tmp.c_str();
    if (callbackInstance != nullptr)
        callbackInstance(tmsg, (int)type, (int)strlen(tmsg));
}