//
// Created by doominik on 5.4.2024.
//

#include "SportsEvent.h"

std::string SportsEvent::typToStr(TypeOfSport typeOfSport1) const {
    switch (typeOfSport1) {
        case(TypeOfSport::soccer):
            return "soccer";
        case(TypeOfSport::tenis):
            return "tenis";
        case(TypeOfSport::basketball):
            return "basketball";
        default: return "Unknown";
    }
}

std::string SportsEvent::toString() const {
    return Event::toString()
           +"\n vrsta sporta "+ typToStr(typeOfSport)+"\n";

}

SportsEvent::SportsEvent(EventAgeGroup eventAgeGroup, Location *place, const DateTime &startDateTime,
                         const DateTime &endDateTime, const std::string &title, float price, uint numTickets,
                         TypeOfSport typeOfSport) : Event(eventAgeGroup, place, startDateTime, endDateTime, title,
                                                          price, numTickets), typeOfSport(typeOfSport) {}
