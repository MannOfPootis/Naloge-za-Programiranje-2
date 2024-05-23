//
// Created by doominik on 16.4.2024.
//

#ifndef NALOGA0701_VECTORUTIL2_H
#define NALOGA0701_VECTORUTIL2_H

#include <iostream>
#include <sstream>
#include "vector"
#include "Point.h"
#include <string>
#include <cstdlib>

template<typename T>
void fillDefault(std::vector<T> &vector, int n) {
    for (int i = 0; i < n; i++) {
        vector.push_back(T());
    }
}

void fillDefault(std::vector<int> &vector, int n) {
    for (int i = 0; i < n; i++) {
        vector.push_back(rand());
    }
}

template<typename T>
void print(std::vector<T> vector) {
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i];
    }
}

template<typename T>
std::vector<float> reverse(std::vector<T> &vector) {
    for (int i = 0; i < vector.size() / 2; i++) {
        T temp = vector[i];
        vector[i] = vector[vector.size() - i - 1];
        vector[vector.size() - i - 1] = temp;
    }
    return vector;

}

template<typename T>
std::vector<int> toInt(std::vector<T> vector) {
    std::vector<int> box;
    for (int i = 0; i < vector.size(); i++) {
        std::stringstream ss;
        try {
            ss << vector[i];
            std::cout << ss.str();
            box.push_back(stoi(ss.str()));
        }
        catch (const std::invalid_argument& b) {
            std::cout << "The value " << ss.str() << " is not a number: " << b.what() << " ";
        }

    }
    return box;
}

template<typename T>
std::vector<T> deepCopy(std::vector<T> joe) {
    std::vector<T> box;
    for (T B: joe) {
        box.push_back(B);
    }
    return box;
}

std::vector<Point> deepCopy(std::vector<Point> joe) {
    std::vector<Point> box;
    for (Point B: joe) {
        box.push_back(Point(B));
    }
    return box;
}

#endif //NALOGA0701_VECTORUTIL2_H
