#include <iostream>
#include "common.hpp"
#include "logger_factory.hpp"

using namespace std;

int main() {
    ILogger* logger = LoggerFactory::createLogger(LogLevel::INFO);
    logger->log(LogLevel::INFO);
    delete logger; // Clean up the allocated memory
    ILogger* logger1 = LoggerFactory::createLogger(LogLevel::DEBUG);
    logger1->log(LogLevel::DEBUG);
    delete logger1; // Clean up the allocated memory
    ILogger* logger2 = LoggerFactory::createLogger(LogLevel::ERROR);
    logger2->log(LogLevel::ERROR);
    delete logger2; // Clean up the allocated memory

    return 0;
}