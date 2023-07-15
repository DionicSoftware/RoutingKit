// source: https://stackoverflow.com/questions/43732825/use-debug-log-from-c

#ifndef UNITY_LOGGER
#define UNITY_LOGGER

#include <stdio.h>
#include <string>
#include <cstring>
#include <sstream>

#ifdef _MSC_VER
#pragma once
#ifdef ROUTINGKIT_EXPORTS
/* We are building this library */
#   define ROUTINGKIT_API extern "C" __declspec(dllexport)
#else
/* We are using this library */
#   define ROUTINGKIT_API extern "C" __declspec(dllimport)
#endif
#else
    #define ROUTINGKIT_API extern "C"
#endif


extern "C" typedef void (*LogCallback) (const char* message, int type, int size);
extern "C" LogCallback callbackInstance;


ROUTINGKIT_API void register_debug_callback(LogCallback callback);
ROUTINGKIT_API void test_debug();


enum class LogType { Log, Warning, Error };

class UnityDebug
{
public:
    static void Log(const char* message, LogType type = LogType::Log);
    static void Log(const std::string message, LogType type = LogType::Log);
    static void Log(const int message, LogType type = LogType::Log);
    static void Log(const char message, LogType type = LogType::Log);
    static void Log(const float message, LogType type = LogType::Log);
    static void Log(const double message, LogType type = LogType::Log);
    static void Log(const bool message, LogType type = LogType::Log);

private:
    static void send_log(const std::stringstream &ss, const LogType &type);
};


#endif
