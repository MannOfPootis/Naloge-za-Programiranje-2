//
// Created by doominik on 4.4.2024.
//

#include "Concert.h"

Concert::Concert(EventAgeGroup eventAgeGroup, Location *place, const DateTime &startDateTime,
                 const DateTime &endDateTime, const std::string &title, float price, uint numTickets,
                 const std::string &performer, ConcertType concertType) : Event(eventAgeGroup, place, startDateTime,
                                                                                endDateTime, title, price, numTickets),
                                                                          performer(performer),
                                                                          concertType(concertType) {}


std::string Concert::toString() const {
    return Event::toString()+"\nigra pa "+ performer+
    "\n tipa "+ strConcertType()+"\n";
}

std::string Concert::strConcertType() const {
    switch (concertType) {
        case(ConcertType::Rock):
            return "Rock";
        case(ConcertType::Pop):
            return "Pop";
        case(ConcertType::Classical):
            return "Classical";
        case(ConcertType::Metal):
            return "Metal";
        default: return "Unknown";
    }
}

