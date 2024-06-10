//
// Created by doominik on 31.5.2024.
//

#ifndef NALOGA1101_INVALIDLOCATIONEXCEPTION_H
#define NALOGA1101_INVALIDLOCATIONEXCEPTION_H


#include <exception>
#include <string>

class InvalidLocationException: public std::exception {
    static int ctr;

    std::string message;
public:
    InvalidLocationException(){
        ctr++;
        message = "Invalid location detected " +std::to_string(ctr);

    }
    const char* what() const noexcept override {
        return message.c_str();
    }

};


#endif //NALOGA1101_INVALIDLOCATIONEXCEPTION_H
