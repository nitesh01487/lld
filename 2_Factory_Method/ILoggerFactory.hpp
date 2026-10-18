#pragma once
#include <iostream>
#include "ilogger.hpp"
#include "DebugLogger.hpp"
#include "InfoLogger.hpp"
#include "ErrorLogger.hpp"

class ILoggerFactory {
public:
    virtual ILogger* createLogger(LogLevel level) = 0;
};