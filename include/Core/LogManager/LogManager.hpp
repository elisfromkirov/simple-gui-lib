#ifndef __LOG_MANAGER_HPP__
#define __LOG_MANAGER_HPP__

#include <cassert>
#include <cstdarg>
#include <cstdint>
#include <cstdio>

class LogManager {
public:
    static LogManager* GetInstance();

    void Release();

    void Print(const char* format, ...);

private:
    LogManager();
    ~LogManager();

    LogManager(const LogManager& other);
    LogManager& operator=(const LogManager& other);

    static LogManager* singleton;

private:
    static const char* kLogFileName;

    FILE* log_file_;
};

#endif // __LOG_MANAGER_HPP__
