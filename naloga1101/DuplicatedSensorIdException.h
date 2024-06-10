#pragma once
#include <exception>
#include <string>

class DuplicatedSensorIdException : public std::exception {
private:
    std::string message;
public:
    DuplicatedSensorIdException(int id) {
        message = "Duplicated sensor ID detected: " + std::to_string(id);
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};