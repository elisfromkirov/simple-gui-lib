#include "Core/LogManager/LogManager.hpp"

const char* LogManager::kLogFileName{"log.txt"};

LogManager* LogManager::singleton{nullptr};

LogManager* LogManager::GetInstance() {
    if (singleton == nullptr) {
        singleton = new LogManager();
    }

    return singleton;
}

void LogManager::Release() {
    delete this;
}

LogManager::LogManager()
    : log_file_{nullptr} {
    log_file_ = fopen(kLogFileName, "w");
    assert(log_file_ != nullptr);
}

LogManager::~LogManager() {
    assert(log_file_ != nullptr);

    fclose(log_file_);
}

void LogManager::Print(const char* format, ...) {
    assert(log_file_ != nullptr);
    assert(format    != nullptr);

    va_list args;
    va_start(args, format);
    vfprintf(log_file_, format, args);
    va_end(args);

    fflush(log_file_);
}
