//
// Created by doominik on 26.3.2024.
//

#include "EventOrganizer.h"

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
    for(int i=0;i<repitore.size();i++) {
        if (repitore[i].getId() == id) {
            return repitore[i].sellTicket();
        }
    }
    return false;   

}

EventOrganizer::EventOrganizer(const std::string &name, const std::vector<Event> &repitore,
                               const std::string &webAdress) : name(name), repitore(repitore), webAdress(webAdress) {}
const std::string EventOrganizer::toString() {
    std::stringstream ss;
    ss<<"name: "<<name<<" adress: "<<webAdress<<"\n listed event repitore:";
    for (int i =0;i<repitore.size();i++){
        ss<<repitore[i].toString()<<"\n";
    }
    std::string sussy =ss.str();
    return sussy;
}
void EventOrganizer::addEvent(Event e) {
    repitore.push_back(e);

}