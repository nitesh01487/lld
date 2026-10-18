#include "ILoggerFactory.hpp"

class InfoLoggerFactory : public ILoggerFactory {
public:
    ILogger* createLogger(LogLevel level) {
        return new InfoLogger(); // For simplicity, always returning InfoLogger
    }
};