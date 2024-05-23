//
// Created by doominik on 26.3.2024.
//

#include "EventOrganizer.h"
#include "iostream"

EventOrganizer::EventOrganizer(const std::string &name,
                               const std::string &webAdress) : name(name), webAdress(webAdress) {}

const std::string &EventOrganizer::getName() const {
    return name;
}

const std::string &EventOrganizer::getWebAdress() const {
    return webAdress;
}

void EventOrganizer::setName(const std::string &name) {
    EventOrganizer::name = name;
}

void EventOrganizer::setWebAdress(const std::string &webAdress) {
    EventOrganizer::webAdress = webAdress;
}

bool EventOrganizer::sellTicket(int id) {
    for (int i = 0; i < repitore.size(); i++) {
        if (repitore[i]->getId() == id) {
            return repitore[i]->sellTicket();
        }
    }
    return false;

}

const std::string EventOrganizer::toString() {
    std::stringstream ss;
    ss << "name: " << name << " adress: " << webAdress << "\n listed event repitore:";
    for (int i = 0; i < repitore.size(); i++) {
        ss << repitore[i]->toString() << "\n";
    }
    std::string sussy = ss.str();
    return sussy;
}

void EventOrganizer::addEvent(Event *e) {
    if (hasConflictingSchedule(e)) {
        std::cout << "pršl je do konflikta";
        return;
    }
    repitore.push_back(e);

}

std::vector<Event*> EventOrganizer::getEventByStatus(EventStatus status) {
    std::vector<Event*> box;
    for (int i = 0; i < this->repitore.size(); i++) {
        if (repitore[i]->getEventStatus() == status)
            box.push_back(repitore[i]);
    }
    return box;
}

const std::vector<Event*> &EventOrganizer::getRepitore() const {
    return repitore;
}

const bool EventOrganizer::hasConflictingSchedule(Event *event) {
    for (int i = 0; i < repitore.size(); i++) {
        if (repitore[i]->getPlace() == event->getPlace()) {
            int cntrR = 0;
            int cntrL = 0;

            cntrR += int(event->getStartDateTime().toSeconds() <= repitore[i]->getStartDateTime().toSeconds());

            cntrR += int(event->getStartDateTime().toSeconds() <= repitore[i]->getEndDateTime().toSeconds());

            cntrL += int(event->getEndDateTime().toSeconds() >= repitore[i]->getEndDateTime().toSeconds());

            cntrL += int(event->getEndDateTime().toSeconds() >= repitore[i]->getStartDateTime().toSeconds());
            if (cntrL > 0 && cntrR > 0) {
                return true;
            }
        }
    }
    return false;
}

EventOrganizer::~EventOrganizer() {
    for (int i=0;i<repitore.size();i++){
        delete repitore[i];
    }

}

