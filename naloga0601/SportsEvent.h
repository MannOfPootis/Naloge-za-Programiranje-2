//
// Created by doominik on 5.4.2024.
//

#ifndef NALOGA0401_SPORTSEVENT_H
#define NALOGA0401_SPORTSEVENT_H

#include "Event.h"
enum class TypeOfSport{soccer,tenis,basketball};

class SportsEvent : public Event{
    TypeOfSport typeOfSport;
private:
    std::string typToStr(TypeOfSport typeOfSport1) const;
public:
    std::string toString() const override;

    SportsEvent(EventAgeGroup eventAgeGroup, Location *place, const DateTime &startDateTime,
                const DateTime &endDateTime, const std::string &title, float price, uint numTickets,
                TypeOfSport typeOfSport);


};


#endif //NALOGA0401_SPORTSEVENT_H
