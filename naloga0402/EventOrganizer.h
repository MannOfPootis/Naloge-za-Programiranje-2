//
// Created by doominik on 26.3.2024.
//

#ifndef NALOGA0401_EVENTORGANIZER_H
#define NALOGA0401_EVENTORGANIZER_H
#include "Event.h"
#include "vector"
class EventOrganizer {
public:
    EventOrganizer(const std::string &name, const std::string &webAdress);

    const std::string &getName() const;

    const std::string &getWebAdress() const;

    std::vector<Event> getEventByStatus(EventStatus status);
    bool sellTicket(int id);

    const std::string toString();
    const bool hasConflictingSchedule(Event event);
    void setName(const std::string &name);
    void addEvent(Event e);

    void setWebAdress(const std::string &webAdress);

    const std::vector<Event> &getRepitore() const;


private:
    std::string name;
    std::vector<Event> repitore;
    std::string webAdress;

};


#endif //NALOGA0401_EVENTORGANIZER_H
