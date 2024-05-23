#include <iostream>
#include "Date.h"

int main() {
    // Creating Date objects with different scenarios
    Date date1(7, 3, 2024);  // Valid date
    Date date2(29, 2, 2024);
    Date date3(35, 1, 2024);
    Date date4(31, 12, 2022);
    Date date5(29, 2, 2023);
    std::cout << "Date 1: " << date1.toString() << std::endl;
    std::cout << "Date 2: " << date2.toString() << std::endl;
    std::cout << "Date 3: " << date3.toString() << std::endl;
    std::cout << "Date 4: " << date4.toString() << std::endl;
    std::cout << "Date 5: " << date5.toString() << std::endl;
    std::cout<< "today's Date:"<< Date::getTodysDate().toString()<<std::endl;

    // Testing isLeapYear method
    unsigned int testYear = 2024;
    std::cout << testYear << " is leap year? " << (Date::isLeapYear(testYear) ? "Yes" : "No") << std::endl;

    // Testing getDaysInMonth method
    unsigned int testMonth = 2; // February
    unsigned int testYear2 = 2023; // Non-leap year
    std::cout << "Number of days in month " << testMonth << " in year " << testYear2 << ": " << Date::getDaysInMonth(testMonth, testYear2) << std::endl;

    // Testing isDateValid method
    unsigned int testDay = 29;
    unsigned int testMonth2 = 2;
    unsigned int testYear3 = 2023;
    std::cout << "Is " << testDay << "." << testMonth2 << "." << testYear3 << " valid? " << (Date::isDateValid(testDay, testMonth2, testYear3) ? "Yes" : "No") << std::endl;

    return 0;
}
