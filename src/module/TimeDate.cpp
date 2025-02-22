#include "TimeDate.h"

#include <ctime>

std::string getDate() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    return std::to_string(localTime->tm_year + 1900) + "-" + std::to_string(localTime->tm_mon + 1) + "-" + std::to_string(localTime->tm_mday);
}

std::string getTime() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    return std::to_string(localTime->tm_hour) + ":" + std::to_string(localTime->tm_min) + ":" + std::to_string(localTime->tm_sec);  
}

std::string getDateTime() {
    return getDate() + " " + getTime();
}