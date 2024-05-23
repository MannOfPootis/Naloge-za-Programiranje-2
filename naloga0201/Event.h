//
// Created by doominik on 11.3.2024.
//

#ifndef NALOGA0201_EVENT_H
#define NALOGA0201_EVENT_H



#include "string"
class Event {
    std::string title;
    float price;
    uint  numTickets;
public:
    Event();
    Event(std::string title,float price,uint numTickets);
    void setTitle(const std::string &title);

    void setPrice(float price);

    void setNumTickets(uint numTickets);

    const std::string &getTitle() const;

    float getPrice() const;

    uint getNumTickets() const;
    std::string toString()const;
    void print()const;

};


#endif //NALOGA0201_EVENT_H
