//
// Created by doominik on 26.3.2024.
//

#ifndef NALOGA0401_EVENTORGANIZER_H
#define NALOGA0401_EVENTORGANIZER_H
#include "Event.h"
#include "vector"
class EventOrganizer {
public:
    const std::string &getName() const;

    const std::string &getWebAdress() const;
    bool sellTicket(int id);

    EventOrganizer(const std::string &name, const std::vector<Event> &repitore, const std::string &webAdress);
    const std::string toString();
    void setName(const std::string &name);
    void addEvent(Event e);

    void setWebAdress(const std::string &webAdress);


private:
    std::string name;
    std::vector<Event> repitore;
    std::string webAdress;

};


#endif //NALOGA0401_EVENTORGANIZER_H
