#include <iostream>
#include "EventOrganizer.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    EventAgeGroup a=Adult;
    Location ljublana("šiška 12","šiška","ljubljana","slovenia");
    std::vector<Event> joshpitore;
    EventOrganizer josh("josh",joshpitore,"http://rit/me/boli.si");
    Event event1(a, &ljublana, Date::getTodysDate(), "dogodek 1", 0.01, 420);
    josh.addEvent(event1);
    std::cout<<josh.toString();
    return 0;
}
