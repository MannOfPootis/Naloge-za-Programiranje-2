//
// Created by doominik on 26.3.2024.
//

#ifndef NALOGA0401_EVENTORGANIZER_H
#define NALOGA0401_EVENTORGANIZER_H

#include <algorithm>
#include <iostream>
#include "vector"
#include "Concert.h"


class PrintIfConcert {
public:
    void operator()(Event* e) {
        Concert* concert = dynamic_cast<Concert*>(e);
        if (concert) {
            std::cout<< e->toString()<< "Concert event found!" << std::endl;
        }
    }
};
class EventOrganizer {
public:
    EventOrganizer(const std::string &name, const std::string &webAdress);

    const std::string &getName() const;

    const std::string &getWebAdress() const;

    std::vector<Event*> getEventByStatus(EventStatus status);
    bool sellTicket(int id);

    const std::string toString();
    const bool hasConflictingSchedule(Event *event);
    void setName(const std::string &name);
    void addEvent(Event *e);

    void setWebAdress(const std::string &webAdress);

    const std::vector<Event*> &getRepitore() const;
    void printEvents(PrintIfConcert f){
        std::for_each(repitore.begin(), repitore.end(), f);
    };
    Event* find(bool (*f)(Event*)){


        for(Event* uck:repitore){
            if(f(uck)){
                return uck;
            }
        }
    };
    void sort(bool (*f)(Event*, Event*)){//boobl sort ker se mi ne da
        for(bool sorted= false;!sorted;sorted=true){
            for(int j=0;j<repitore.size()-1;j++){
                if(f(repitore[j],repitore[j+1])){
                    Event* temp=repitore[j];
                    repitore[j]=repitore[j+1];
                    repitore[j+1]=temp;
                    sorted=false;
                }
            }
        }
    };
    void bogoShort(bool (*f)(Event*, Event*)){//dont call this with a big list but it is funnny
        for(bool sorted= false;!sorted;sorted=true){
            for(int j=0;j<repitore.size()-1;j++){
                if(f(repitore[j],repitore[j+1])){
                    int i=rand()%repitore.size();
                    Event* temp=repitore[j];
                    repitore[j]=repitore[i];
                    repitore[i]=temp;
                    sorted=false;
                }
            }
        }
    };


private:
    std::string name;
    std::vector<Event*> repitore;
    std::string webAdress;

};


#endif //NALOGA0401_EVENTORGANIZER_H
