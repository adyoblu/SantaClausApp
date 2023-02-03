#define _CRT_SECURE_NO_WARININGS
#pragma once
#include <fstream>
#include <chrono>
#include <iomanip>

class Logger {
private:
    static Logger* instance;
    std::ofstream logFile;
    Logger() {}
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    static Logger* getInstance() {
        if (!instance) {
            instance = new Logger();
        }
        return instance;
    }
    void log(std::string message) {
        logFile.open("logger.txt", std::ios_base::app);
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        tm local_tm;
        localtime_s(&local_tm, &in_time_t);
        logFile << std::put_time(&local_tm, "%Y-%m-%d %X") << " " << message << std::endl;
        close();
    }
    void close() {
        logFile.close();
    }
};
