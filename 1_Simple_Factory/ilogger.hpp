#pragma once
#include <iostream>
#include "common.hpp"

using namespace std;

class ILogger {
public:
    virtual void log(LogLevel level) = 0; // Pure virtual function
    virtual ~ILogger() {}; // Virtual destructor
};