#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <cctype>
#include "Printer.h"
int main() {
    Printer printer;

    // Dodajanje elementov
    printer.add("First job to print");
    printer.add(123123);
    printer.add(std::vector<int>{132, 453});
    printer.add(std::vector<std::string>{"prog", "prog2"});
    std::cout<<printer.toString()<<"\n";

    auto isShort = [](const std::string& s) { return s.length() < 3; };
    auto isInVector = [](const std::vector<std::string>& vec) {
        return [&vec](const std::string& s) {
            return std::find(vec.begin(), vec.end(), s) != vec.end();
        };
    };
    auto lengthCompare = [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
    };
    auto needsCorrection = [](const std::string& s) {
        return !s.empty() && std::islower(s[0]);
    };
    auto capitalize = [](std::string& s) {
        if (!s.empty() && std::isalpha(s[0])) {
            s[0] = std::toupper(s[0]);
        }
    };

    printer.remove(isShort);

    std::vector<std::string> vec = {"prog", "prog2"};
    printer.remove(isInVector(vec));

    printer.sort(lengthCompare);

    printer.checkAndCorrect(needsCorrection, capitalize);

    printer.findAndReplace("First", "Initial");

    printer.unique();
    if(printer.contains("132","132","453"))
        std::cout<<"\n\tsusssesfull\n";
    printer.print();

    return 0;
}
