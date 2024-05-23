//
// Created by doominik on 16.4.2024.
//

#ifndef NALOGA0701_VECTORUTIL2_H
#define NALOGA0701_VECTORUTIL2_H

#include <iostream>
#include <sstream>
#include "vector"
#include "PrintUtility.h"
#include "Point.h"
#include "ColorCode.h"
template<typename T>
void fillDefault(std::vector<T> &vector, int n) {
    for(int i=0;i<n;i++){
        vector.push_back(T());
    }
}
void fillDefault(std::vector<int> &vector, int n) {
    for(int i=0;i<n;i++){
        vector.push_back(rand());
    }
}
template<typename T>
void print(std::vector<T> vector)  {
for(int i=0;i<vector.size();i++){
    std::cout<<vector[i];
}
}
template<typename T>
std::vector<float> reverse(std::vector<T> &vector)  {
    for(int i=0;i<vector.size()/2;i++){
        T temp= vector[i];
        vector[i]=vector[vector.size()-i-1];
        vector[vector.size()-i-1]=temp;
    }
    return  vector;

}
template< typename T>
void printColor(std::vector<T> vector, ColorCode color=ColorCode::Green){
    for(int i=0;i<vector.size();i++){
        std::cout << "\033[" << (int) color << "m" << vector[i]<< "\033[0m" << std::endl;
    }
};
template<typename T>
std::vector<std::vector<T>> sliceRot(std::vector<T> stuff,int n=3){
    std::vector<std::vector<T>> box;
    std::vector<T> bmx;
    for(int i =0;i<stuff.size();i++){
        if(i%n>=box.size()){
            box.push_back(bmx);
        }
        box[i%n].push_back(stuff[i]);
    }
    return box;
}
template<typename T>
std::vector<std::vector<T>> slice(std::vector<T> stuff,int n=3) {
    std::vector<std::vector<T>> box;
    std::vector<T> bmx;
    box.push_back(bmx);
    for(int i =0;i<stuff.size();i++){
        if(box[box.size()-1].size()>=n){
            box.push_back(bmx);
        }
        box[box.size()-1].push_back(stuff[i]);
    }
    return box;
}

template <typename T>
std::vector<int> toInt(std::vector<T> vector){
    std::vector<int> box;
    for(int i =0;i<vector.size();i++){
        try{
            std::stringstream ss;
            ss<<vector[i];
            std::cout<<ss.str();
            if(!isdigit(ss.str()[0])) {
                throw 15;
            }
            box.push_back(stoi(ss.str()));}
        catch (int num){
            std::cout<<"not a number cant sry:(";
        }

    }
    return box;
}
template<typename T,typename L>
std::vector<L> cast(std::vector<T> noWayThisWorks){
    std::vector<L> box;
    for(int i=0;i<noWayThisWorks.size();i++){
        box.push_back((L)noWayThisWorks[i]);
    }
    return box;
}
std::vector<Point> cast(std::vector<float> noWayThisWorks){
    std::vector<Point> box;
    for(int i=0;i<noWayThisWorks.size();i++){
        box.push_back(Point(noWayThisWorks[i],noWayThisWorks[i]));
    }
    return box;
}
template<typename T>
void remove(std::vector<T> liver,std::vector<T> knife){
    for(int i=0;i<liver.size();i++){
        for(int j=0;j<knife;j++){
            if(liver[i]==knife[j]){
                liver.erase(i);
            }
        }
    }//ik it aint e
}
template<typename T>
std::vector<T> subVector(std::vector<T> uberVector,int sart,int end){
    if(sart>end||sart<0||end>uberVector.size()){
        throw std::invalid_argument("out of bounds ofa arraay ");

    }
    std::vector<T> box;
    for(int i=sart;i<end;i++){
        box.push_back(uberVector[i]);
    }
    return box;
}

#endif //NALOGA0701_VECTORUTIL2_H
