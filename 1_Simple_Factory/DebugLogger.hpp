#pragma once
#include <iostream>
#include "ilogger.hpp"

class DebugLogger : public ILogger {
public:
    void log(LogLevel level);
};