#include <iostream>
#include "CircularLinkedList.h"
int main() {
    CircularLinkedList<int> inatary;
    inatary.add(1);
    inatary.add(2);

    inatary.add(3);

    inatary.add(4);
    inatary.add(5);

   // int numr=inatary.at(1);
    inatary.insertBefore(5,80085);
    inatary.insertBefore(1,80085);

    inatary.insertBefore(2,80085);




    int size=inatary.sizeSlow()+1;
    for(int i =0;i<size;i++){
        std::cout<<inatary.at(i)<<"\n";
    }



    return 0;
}
