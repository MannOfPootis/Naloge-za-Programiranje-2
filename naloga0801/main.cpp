#include <iostream>
#include "PriortyQueue.h"
#include "memory"
int main() {
    PriorityQueue<int> bongus;
    PriorityQueue<string> strimg;
    PriorityQueue<shared_ptr<Time>> times;
        bongus.add(1, Priority::Low );
        bongus.add(2,Priority::High);
        bongus.add(3,Priority::High);
        bongus.add(4,Priority::High);
        bongus.add(5,Priority::High);
        bongus.add(6,Priority::High);
        std::cout<<bongus.toString()<<"\n";

        strimg.add("dsaysy",Priority::Low);
        strimg.add("coping",Priority::High);


        times.add(make_shared<Time>(1,1,12), Priority::High);
        times.add(make_shared<Time>(1,1,2), Priority::High);
        times.add(make_shared<Time>(1,1,3), Priority::High);
    try {
        std::cout<<times.getMax()->toString()<<"\n";


        std::cout<<strimg.getMax()<<"\n";

        std::cout << strimg.pop().second<<"\n";
        std::cout << strimg.pop().second<<"\n";


        std::cout << bongus.getMax()<<"\n";

        std::cout << bongus.pop().second;
        std::cout << bongus.pop().second;
        std::cout << bongus.pop().second;
        std::cout << bongus.pop().second;
        std::cout << bongus.pop().second;

    }catch (exception e){
        std::cout<<e.what();
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
