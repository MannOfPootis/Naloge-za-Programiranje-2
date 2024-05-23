//
// Created by doominik on 26.3.2024.
//

#ifndef NALOGA0401_EVENT_H
#define NALOGA0401_EVENT_H
#include "Sponsor.h"
#include "Location.h"
#include "Date.h"
#include "string"
#include "DateTime.h"
enum EventStatus{Upcoming, Ongoing,Completed};
enum EventAgeGroup{Child,Adult,Senior,all};
class Event {
protected:
    static int recentInt;
    EventAgeGroup eventAgeGroup;
    Location* place;
    DateTime startDateTime;
    DateTime endDateTime;
    std::string title;
    float price;
    uint id;
    uint  numTickets;
    std::vector<Sponsor*> sponsors;
public:
   /* Event(EventAgeGroup eventAgeGroup, Location *place, const DateTime &startDateTime, const DateTime &endDateTime,
          const std::string &title, float price, uint numTickets);*/


    void addSponsor( Sponsor *s);
    bool sellTicket();

public:

    std::string strEventAgeGroup() const;
    /*Event(EventAgeGroup eventAgeGroup, Location *place, DateTime Stardate,DateTime , const std::string &title, float price,
          uint numTickets);*/

    EventStatus getEventStatus();
    Location *getPlace() const;

    void setStartDateTime(const DateTime &startDateTime);

    void setEndDateTime(const DateTime &endDateTime);

    Event(EventAgeGroup eventAgeGroup, Location *place, const DateTime &startDateTime, const DateTime &endDateTime,
          const std::string &title, float price, uint numTickets);

    //const DateTime &getDate() const;
    void setPlace(Location *place);

    const DateTime &getStartDateTime() const;

    const DateTime &getEndDateTime() const;

    //void setDate(const DateTime &date);
    EventAgeGroup getEventAgeGroup() const;
    uint getId() const;
    //Event();
    // Event(std::string title,float price,uint numTickets);
    //Event(std::string title,float price,uint numTickets,std::string location);

    void setEventAgeGroup(EventAgeGroup eventAgeGroup);
    void setId(uint id);
    /*Event(EventAgeGroup eventAgeGroup, Location *place, const DateTime &date, const std::string &title, float price,
          uint numTickets, const std::string &location);*/
    void setTitle(const std::string &title);
    void setPrice(float price);
    void setNumTickets(uint numTickets);
    //Event(const std::string &title, float price, uint numTickets);

    const std::string &getTitle() const;
    float getPrice() const;
    uint getNumTickets() const;

    virtual std::string toString()const;
    void print()const;
};




#endif //NALOGA0401_EVENT_H
