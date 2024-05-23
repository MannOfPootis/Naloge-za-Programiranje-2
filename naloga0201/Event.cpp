//
// Created by doominik on 11.3.2024.
//

#include "Event.h"
#include "iostream"
Event::Event() {

}
Event::Event(std::string titlea,float pricea, uint numTicketsa) {
    price=pricea;
    title=titlea;
    numTickets=numTicketsa;
}
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
    return title+" stane " + std::to_string(price) +" in ima "+ std::to_string(numTickets) +" vztopnic";
}

void Event::print() const {
    std::cout<<toString();
}


