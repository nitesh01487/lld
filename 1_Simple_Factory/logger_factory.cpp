#include "logger_factory.hpp"
#include "InfoLogger.hpp"
#include "DebugLogger.hpp"
#include "ErrorLogger.hpp"

using namespace std;

ILogger* LoggerFactory::createLogger(LogLevel level) {
    switch (level) {
        case LogLevel::INFO:
            return new InfoLogger();
        case LogLevel::DEBUG:
            return new DebugLogger();
        case LogLevel::ERROR:
            return new ErrorLogger();
        default:
            return nullptr;
    }
}