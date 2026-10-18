#pragma once
#include <iostream>
#include "ilogger.hpp"

using namespace std;

class ErrorLogger : public ILogger {
public:
    void log(LogLevel level);
};