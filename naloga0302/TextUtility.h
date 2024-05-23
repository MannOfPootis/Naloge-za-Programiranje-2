//
// Created by doominik on 21.3.2024.
//

#ifndef NALOGA0302_TEXTUTILITY_H
#define NALOGA0302_TEXTUTILITY_H


#include <string>
#include <vector>

class TextUtility {
private:
    TextUtility(); // Privatni privzeti konstruktor

public:
    static std::string floatToString(float value, int numDecimals);
    static int countWords(const std::string& str);
    static std::string capitalizeWords(const std::string& str);
    static std::vector<int> extractIntNumbers(const std::string& str);

    // Dodatna metoda: zamenja vse samoglasnike v nizu z zvezdico (*)
    static std::string replaceVowels(const std::string& str);
    static int indexOf(const std::string &str, const std::string &substr);
};


#endif //NALOGA0302_TEXTUTILITY_H
