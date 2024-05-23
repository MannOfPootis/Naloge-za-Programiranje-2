//
// Created by doominik on 21.3.2024.
//

#include "TextUtility.h"
#include <iostream>
#include <sstream>
#include <algorithm>

TextUtility::TextUtility() {}

int TextUtility::indexOf(const std::string &str, const std::string &substr) {
    int j = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == substr[j]) {
            if (j == substr.size() - 1)
                return i - j;
            j++;
        } else {
            j = 0;
        }
    }
    return -1;
}

std::string TextUtility::floatToString(float value, int numDecimals) {
    std::stringstream ss;
    ss.precision(numDecimals);
    ss << std::fixed << value;
    return ss.str();
}

int TextUtility::countWords(const std::string &str) {
    int count = 0;
    bool antidupe= true;
    for (char c: str) {
        if (std::isspace(c)) {
            antidupe= true;
        }
        else if(!std::isspace(c)&&antidupe)
        {
            count++;
            antidupe= false;
        }
    }
    return count;
}

std::string TextUtility::capitalizeWords(const std::string &str) {
    std::string result = str;
    bool capitalizeNext = true;
    for (int i = 0; i < result.length(); i++) {
        if (std::isspace(result[i])) {
            capitalizeNext = true;
        } else if (capitalizeNext) {
            result[i] = std::toupper(result[i]);
            capitalizeNext = false;
        }
    }
    return result;
}

std::vector<int> TextUtility::extractIntNumbers(const std::string &str) {
    std::vector<int> numbers;
    std::string numStr;
    for (char c: str) {
        if (std::isdigit(c) || c == '-') {
            numStr += c;
        } else if (!numStr.empty()) {
            numbers.push_back(std::stoi(numStr));
            numStr.clear();
        }
    }
    if (!numStr.empty()) {
        numbers.push_back(std::stoi(numStr));
    }
    return numbers;
}

std::string TextUtility::replaceVowels(const std::string &str) {
    std::string result = str;
    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < result.length(); i++) {
        if (std::find(vowels.begin(), vowels.end(), result[i]) != vowels.end()) {
            result[i] = '*';
        }
    }
    return result;
}

