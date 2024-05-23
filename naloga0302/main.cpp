#include "TextUtility.h"
#include <iostream>

int main() {
    std::cout << "convert to stirng: " << TextUtility::floatToString(12.45354, 3) << std::endl;
    std::cout << "number of words right here: " << TextUtility::countWords("pre        štej") << std::endl;
    std::cout << "capitalisations: " << TextUtility::capitalizeWords("zdravo") << std::endl;
    std::cout << "extracted ints: ";
    for (int num : TextUtility::extractIntNumbers("lorem ipSUM dolor sit AMET 12, ConsecTetur adipiscing elit15, sed do eiusmod -16.")) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "censor wowlelsv: " << TextUtility::replaceVowels("lorem ipsum dolor sit amet") << std::endl;

    std::cout << "\nextra test:" << std::endl;
    std::cout << "convertong numerar: " << TextUtility::floatToString(3.14159, 1) << std::endl;
    std::cout << "count words:" << TextUtility::countWords("besed brez ločil") << std::endl;
    std::cout << "capitalize letters" << TextUtility::capitalizeWords("beseda") << std::endl;
    std::cout << "take out integers if empty(1/0=true/false):" << TextUtility::extractIntNumbers("").empty() << std::endl; // Prints true if empty
    std::cout << "replace vowels" << TextUtility::replaceVowels("") << std::endl;
    std::cout << "find the dex" << TextUtility::indexOf("grergegegegegegegeggeg","geg") << std::endl;

    return 0;
}
