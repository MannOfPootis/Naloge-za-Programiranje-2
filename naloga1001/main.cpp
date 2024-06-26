#include <iostream>
#include "EventOrganizer.h"
#include "Time.h"
#include "Concert.h"
#include "SportsEvent.h"

bool ascendingTime(Event *e1,Event *e2){
    return(e1->getStartDateTime().toSeconds()>e2->getStartDateTime().toSeconds());
}
bool ascendingPrice(Event *e1,Event *e2){
    return e1->getPrice()>e2->getPrice();
}
bool ascendingId(Event *e1,Event *e2){
    return e1->getId()>e2->getId();

}
bool isOver18(Event *e){
    return e->getEventAgeGroup()==EventAgeGroup::Adult||e->getEventAgeGroup()==EventAgeGroup::Senior;
}
void something(){
    std::cout<<"something\n";
}
void nothing(){
    std::cout<<"nothing\n";
}

int main() {
   // std::cout << "Hello, World!" << std::endl;
    Time teaime = Time(10, 1, 1000);
   // std::cout << teaime.toString();
    EventAgeGroup a = Adult;
    Location ljublana("šiš 12", "šiška", "ljubljana", "slovenia", Coordinates(1, 1));
    Location maribor("sus 12", "šiška", "maribor", "slovenia", Coordinates(1, 1));
    Location batman("batman 12", "batman", "batman", "turkey", Coordinates(1, 1));

    //std::vector<Event> joshpitore;
    EventOrganizer josh("josh", "http://boli.si");
    Concert *žižek = new Concert(a, &ljublana, DateTime::getCurrentTime(), DateTime::getCurrentTime(),
                                 "BINGOUM BONG", 10, 420, "žižek", Rock);
    Location dobrna("zavrh nad dobrno 14", "Zavrh nad dobrno", "Dobrna", "Slovenia", Coordinates(69.420, 80.085));
    žižek->sellTicket();


    Event *lmao2 = new Event(a, &ljublana, DateTime(Date(1, 1, 2000), Time(1, 1, 1)),
                             DateTime(Date(1, 1, 2010), Time(1, 1, 1)), "oče janez ječmen seje", 0.01, 420);
    Event *lmao1 = new Event(a, &maribor, DateTime::getCurrentTime(), DateTime::getCurrentTime(),
                             "oče janez ječmen seje", 0.01, 420);
    SportsEvent *chesesChasing=  new SportsEvent(a, &batman, DateTime::getCurrentTime(), DateTime::getCurrentTime(),
                                           "Lovimo sir dol po hribu", 0.01, 420, TypeOfSport::soccer);
    SportsEvent *chesesChasingUp=  new SportsEvent(a, &ljublana, DateTime::getCurrentTime(), DateTime::getCurrentTime(),
                                                 "Lovimo sir gor po hribu", 0.01, 420, TypeOfSport::soccer);
    josh.addEvent(žižek);
    josh.addEvent(lmao1);
    josh.addEvent(lmao2);
    josh.addEvent(chesesChasing);
    josh.addEvent(chesesChasingUp);
    //žižek->setPrice(1283);


    // std::cout << "\n" << žižek->getStartDateTime().toString() << " " << žižek->getStartDateTime().toSeconds() << "\n";
    //std::cout << žižek->toString();
    /*std::cout << josh.toString();
    žižek->sellTicket();*/
   // bool a=true;
/*
    josh.sort(ascendingId);
    std::cout << josh.toString();

    josh.sort(ascendingPrice);
    std::cout << josh.toString();
*/
    std::cout << "\n\nEvents for 18+ \n";
    Event* eventOver18 = josh.find(isOver18);
    if(eventOver18 != nullptr)
        std::cout << eventOver18->toString();
    else
        std::cout << "no events";
   /* PrintIfConcert rer;
    josh.printEvents(rer);*/
    josh.conditionIfElse(ascendingPrice,something,nothing);

//    joshpitore[0].sellTicket();
    EventOrganizer john("john", "hoooh");

    //std::cout<<"TUKAJ"<<john.toString();
    return 0;
}
