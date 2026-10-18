#pragma once
#include <iostream>
#include "ilogger.hpp"

using namespace std;

class LoggerFactory {
public:
    static ILogger* createLogger(LogLevel level);
};