//
// Created by doominik on 4.4.2024.
//

#ifndef NALOGA0401_CONCERT_H
#define NALOGA0401_CONCERT_H
#include "Event.h"
enum ConcertType{Rock,Pop,Classical,Metal};
class Concert : public Event {
protected:
    std::string performer;
    ConcertType concertType;
public:
    Concert(EventAgeGroup eventAgeGroup, Location *place, const DateTime &startDateTime, const DateTime &endDateTime,
            const std::string &title, float price, uint numTickets, const std::string &performer,
            ConcertType concertType);

    std::string toString() const override; //std::string toString() const;
    std::string strConcertType() const;
};


#endif //NALOGA0401_CONCERT_H
