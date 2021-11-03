#ifndef __LOG_MANAGER_HPP__
#define __LOG_MANAGER_HPP__

#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstdarg>

class LogManager {
private:
    static const char* kLogFileName;

    static LogManager* singleton;

private:
    LogManager();

public:
    static LogManager* GetLogManager();

public:
    ~LogManager();

    void Print(const char* format, ...);

private:
    FILE* log_file_;
};

#endif // __LOG_MANAGER_HPP__
