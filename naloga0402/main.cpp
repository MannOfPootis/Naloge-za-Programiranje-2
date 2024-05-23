#include <iostream>
#include "EventOrganizer.h"
#include "Time.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Time teaime=Time(10,1,1000);
    std::cout<<teaime.toString();
    EventAgeGroup a=Adult;
    Location ljublana("šiš 12","šiška","ljubljana","slovenia",Coordinates(1,1));
    std::vector<Event> joshpitore;
    EventOrganizer josh("josh","http://boli.si");
    Event žižek(a,&ljublana,DateTime::getCurrentTime(),DateTime::getCurrentTime(),"oče janez ječmen seje",0.01,420);

    Location dobrna("zavrh nad dobrno 14", "Zavrh nad dobrno", "Dobrna","Slovenia",Coordinates(69.420,80.085));
    žižek.sellTicket();
    josh.addEvent(žižek);

    Event lmao2(a,&ljublana,DateTime(Date(1,1,2000), Time(1,1,1)),
                DateTime(Date(1,1,2010), Time(1,1,1)),"oče janez ječmen seje",0.01,420);
    Event lmao1(a,&ljublana,DateTime::getCurrentTime(),DateTime::getCurrentTime(),"oče janez ječmen seje",0.01,420);
    josh.addEvent(lmao1);
    josh.addEvent(lmao2);

    std::cout<<"\n"<<žižek.getStartDateTime().toString()<<" "<<žižek.getStartDateTime().toSeconds()<<"\n";

    std::cout<<josh.toString();
    žižek.sellTicket();
//    joshpitore[0].sellTicket();
    EventOrganizer john("john","hoooh");
    //std::cout<<"TUKAJ"<<john.toString();
    return 0;
}
