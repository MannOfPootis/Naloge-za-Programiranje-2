#include <iostream>
#include <string>
#include <cmath>
#include <string.h>

int min(int a, int b) {
    if (a > b)
        return b;
    return a;
}

int max(int a, int b) {
    if (a < b)
        return b;
    return a;
}

int maxCeil(float a, float b) {
    return max(ceil(a), ceil(b));
}

/*int max(float a ,float b)
{
    return max(ceil(a),ceil(b));
}*/

int maxModified(int a,
                int b) {//I KNOW THIS ISNT THE "BEST" OR "PRETTYEST" WAY OF DOING IT BUT I WILL DO EVERYTHING IN MY POWER TO AVIDUNECESARRY IF STATEMENTS
    int bModified = b / 2 + (int) (b % 2 != 0);//basicly preveri ce je stevilo deljivo z dva in ce je pol ga poveca za 1
    if (a < bModified)//in ja, ni komutativno
        return bModified;
    return a;
}

int inpat() {
    try {
        std::string inputed;
        // bool isnum = true;
        //  string inputed;
        int puted;
        std::cin >> inputed, puted;


        for (int i = 0; i < sizeof(inputed); i++) {
            if (!isdigit(inputed[i])) {
                std::cout << inputed << " is not a number ";
            }

        }
        return puted;

    } catch (char *notNum) {
        std::cout << notNum << " is not a number and therefore is bAD";
        exit(80085);
    }


}

int input() {

    std::string inputed;
    std::cin >> inputed;
    return std::stoi(inputed);


}


void carModel(float wheels, float mirrors, float bodides, int cntWheels, int cntMirrors, int cntBodies) {
    int cars = min(min(wheels / cntWheels, bodides / cntBodies), mirrors / cntMirrors);
    std::cout << "you can make " << cars << " cars" << std::endl;
    wheels -= cars * cntWheels;
    bodides -= cars;
    mirrors -= cars * cntMirrors;
    std::cout << "you still have " << wheels << " wheels" << std::endl;
    std::cout << "you still have " << bodides << " bodies" << std::endl;
    std::cout << "you still have " << mirrors << " mirrors" << std::endl;
    int newCars = maxCeil(maxCeil(bodides / cntBodies, mirrors / cntMirrors), wheels /
                                                                              cntWheels);//I KNOW THIS ISNT THE "BEST" OR "PRETTYEST" WAY OF DOING IT BUT I WILL DO EVERYTHING IN MY POWER TO AVIDUNECESARRY IF STATEMENTS
    std::cout << "you still have to order " << newCars * cntWheels - wheels << " wheels" << std::endl;
    std::cout << "you still have to order " << newCars*cntBodies - bodides << " bodies" << std::endl;
    std::cout << "you still have to order " << newCars * cntMirrors - mirrors << " mirrors" << std::endl;

}

int main() {


    float wheels, bodies, mirrors;
    do {
        std::cout << "tell me how many wheels you have: " << std::endl;
        wheels = input();
        std::cout << "tell me how many bodies you have: " << std::endl;
        bodies = input();
        std::cout << "tell me how many mirrors you have: " << std::endl;
        mirrors = input();
    } while (!(wheels > 0 && bodies > 0 && mirrors > 0));
    std::cout << "tell me what model of car you want" << std::endl;
    int model = input();
    switch (model) {
        case 1:

            carModel(wheels, mirrors, bodies, 4, 2, 1);//LMAO NAPCN SM INPUTU
            break;

        case 2:
            carModel(wheels, mirrors, bodies, 2, 2, 1);
            break;
    }

    return 0;
}
