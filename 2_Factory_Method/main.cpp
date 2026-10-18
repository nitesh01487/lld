#include "InfoLoggerFactory.hpp"
#include "DebugLoggerFactory.hpp"
#include "ErrorLoggerFactory.hpp"

using namespace std;

int main() {
    ILoggerFactory* infoFactory = new InfoLoggerFactory();
    ILogger* logger = infoFactory->createLogger(LogLevel::INFO);
    logger->log(LogLevel::INFO);

    ILoggerFactory* debugFactory = new DebugLoggerFactory();
    ILogger* logger1 = debugFactory->createLogger(LogLevel::DEBUG);
    logger1->log(LogLevel::DEBUG);

    ILoggerFactory* errorFactory = new ErrorLoggerFactory();
    ILogger* logger2 = errorFactory->createLogger(LogLevel::ERROR);
    logger2->log(LogLevel::ERROR);

    delete logger;
    delete logger1;
    delete logger2;

    return 0;
}