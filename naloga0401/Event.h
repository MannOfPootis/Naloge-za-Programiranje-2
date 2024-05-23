//
// Created by doominik on 26.3.2024.
//

#ifndef NALOGA0401_EVENT_H
#define NALOGA0401_EVENT_H

#include "Location.h"
#include "Date.h"
#include "string"

enum EventAgeGroup{Child,Adult,Senior,all};
class Event {
    static int recentInt;
    EventAgeGroup eventAgeGroup;
    Location* place;
    Date date;
    std::string title;
    float price;
    uint id;
    uint  numTickets;


public:
    Event(EventAgeGroup eventAgeGroup, Location *place, const Date &date, const std::string &title, float price,
          uint numTickets);

    Location *getPlace() const;

    const Date &getDate() const;
    void setPlace(Location *place);

    void setDate(const Date &date);
    EventAgeGroup getEventAgeGroup() const;
    uint getId() const;
    //Event();
    // Event(std::string title,float price,uint numTickets);
    //Event(std::string title,float price,uint numTickets,std::string location);

    void setEventAgeGroup(EventAgeGroup eventAgeGroup);
    void setId(uint id);
    Event(EventAgeGroup eventAgeGroup, Location *place, const Date &date, const std::string &title, float price,
          uint numTickets, const std::string &location);
    void setTitle(const std::string &title);
    void setPrice(float price);
    void setNumTickets(uint numTickets);
    bool sellTicket();
    Event(const std::string &title, float price, uint numTickets);

    const std::string &getTitle() const;
    float getPrice() const;
    uint getNumTickets() const;
    std::string toString()const;
    void print()const;
};




#endif //NALOGA0401_EVENT_H
