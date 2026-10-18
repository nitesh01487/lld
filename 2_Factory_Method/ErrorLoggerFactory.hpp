#include "ILoggerFactory.hpp"

class ErrorLoggerFactory : public ILoggerFactory {
public:
    ILogger* createLogger(LogLevel level) {
        return new ErrorLogger(); // For simplicity, always returning ErrorLogger
    }
};