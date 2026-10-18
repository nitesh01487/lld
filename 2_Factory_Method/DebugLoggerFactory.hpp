#pragma once
#include <iostream> 
#include "ILoggerFactory.hpp"

class DebugLoggerFactory : public ILoggerFactory {
public:
    ILogger* createLogger(LogLevel level) {
        return new DebugLogger(); // For simplicity, always returning DebugLogger
    }
};