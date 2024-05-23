//
// Created by doominik on 26.3.2024.
//

#include "Event.h"
#include "iostream"

int Event::recentInt = 0;

/*Event::Event(): Event("adsa",1,1, "joeland") {

}*/
/*Event::Event(std::string titlea,float pricea, uint numTicketsa) {
    price=pricea;
    title=titlea;
    numTickets=numTicketsa;
}*/

/*Event::Event(std::string titlea, float pricea, uint numTicketsa, std::string location) {
    price=pricea;
    title=titlea;
    numTickets=numTicketsa;
    this->location=location;

}*/
uint Event::getNumTickets() const {
    return numTickets;
}

void Event::setTitle(const std::string &title) {
    Event::title = title;
}

void Event::setPrice(float price) {
    Event::price = price;
}

void Event::setNumTickets(uint numTickets) {
    Event::numTickets = numTickets;
}
const std::string &Event::getTitle() const {
    return title;
}

float Event::getPrice() const {
    return price;
}
std::string Event::toString() const {
    return "\nid :"+std::to_string(id) +"( ͡° ͜ʖ ͡°) \n"+title+" stane " + std::to_string(price)
    +" in ima "+ std::to_string(numTickets) +" vztopnic"+ "\n"+
    "za starostno skupino :"+strEventAgeGroup()+
    " in na lokaciji: "+ place->toString()+
    "\nod " +startDateTime.toString() +" do "+endDateTime.toString();
}

void Event::print() const {
    std::cout<<toString();
}



Location *Event::getPlace() const {
    return place;
}

/*const Date &Event::getDate() const {
    return date;
}*/

void Event::setPlace(Location *place) {
    Event::place = place;
}
/*
void Event::setDate(const Date &date) {
    Event::date = date;
}*/

EventAgeGroup Event::getEventAgeGroup() const {
    return eventAgeGroup;
}

void Event::setEventAgeGroup(EventAgeGroup eventAgeGroup) {
    Event::eventAgeGroup = eventAgeGroup;
}
bool Event::sellTicket() {
    numTickets--;
    return numTickets>0;
}
/*
Event::Event(EventAgeGroup eventAgeGroup, Location *place, const Date &date, const std::string &title, float price,
             uint numTickets) : eventAgeGroup(eventAgeGroup), place(place), date(date),
                                                             title(title), price(price), numTickets(numTickets)
                                                             {

    id=++recentInt;

                                                             }*/

uint Event::getId() const {
    return id;
}

void Event::setId(uint id) {
    Event::id = id;
}

Event::Event(EventAgeGroup eventAgeGroup, Location *place, const DateTime &startDateTime, const DateTime &endDateTime,
             const std::string &title, float price, uint numTickets) : eventAgeGroup(eventAgeGroup), place(place),
                                                                       startDateTime(startDateTime),
                                                                       endDateTime(endDateTime), title(title),
                                                                       price(price), numTickets(numTickets) {
    id=++recentInt;
}

const DateTime &Event::getStartDateTime() const {
    return startDateTime;
}

const DateTime &Event::getEndDateTime() const {
    return endDateTime;
}

void Event::setStartDateTime(const DateTime &startDateTime) {
    Event::startDateTime = startDateTime;
}

void Event::setEndDateTime(const DateTime &endDateTime) {
    Event::endDateTime = endDateTime;
}

EventStatus Event::getEventStatus() {
    unsigned long tdy= DateTime::getCurrentTime().toSeconds();
    if(startDateTime.toSeconds()<tdy)
    {
        if(startDateTime.toSeconds()<tdy){
            return Upcoming;
        }
        return Ongoing;
    }
    return Completed;
}

std::string Event::strEventAgeGroup() const {

    switch (eventAgeGroup){
        case(Child):
            return "Cild";
        case(Adult):
            return "Adult";
        case(Senior):
            return "Senior";
        case (all):
            return "All";
    }
    //return std::string();
}

/*Event::Event(EventAgeGroup eventAgeGroup, Location *place, const DateTime &startDateTime, const DateTime &endDateTime,
             const std::string &title, float price, uint id, uint numTickets) : eventAgeGroup(eventAgeGroup),
                                                                                place(place),
                                                                                startDateTime(startDateTime),
                                                                                endDateTime(endDateTime), title(title),
                                                                                price(price),
                                                                                numTickets(numTickets) {
    id=++recentInt;
}*/

