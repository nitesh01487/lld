#pragma once
#include <iostream>
#include "ilogger.hpp"

using namespace std;

class InfoLogger : public ILogger {
public:
    void log(LogLevel level) override;
};