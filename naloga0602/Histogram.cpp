//
// Created by doominik on 11.4.2024.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Histogram.h"
int minElement(std::vector<int> b){
    int sus=b[0];
    for(int i =0;i<b.size();i++)
        if(b[i]<sus)
            sus=b[i];
    return sus;
}

void Histogram::show(ColorCode color,int res) const {
    std::map< int, int> mapa;
    res =res-1;


    for(int i=0;i<data.size();i++) {//tole je possesed
        mapa[data[i]]+=1;
    }
    /*std::cout<<mapa[10];
    std::cout<<mapa[data[1]];*/
    int recent=0;
    std::vector<int> newbox;
    int sum=0;

    for(auto& pair :mapa){//KRE ELEGANTNO LESS GO
        if(sum==0){
            std::cout<<pair.first<<"\t-\t"<<pair.first+res<<":\t";
        }
        sum+=mapa[pair.first];

        for(int i =0;i<mapa[pair.first];i++){
            PrintUtility::print(color,"*");
        }
        if(pair.first>recent+res){
          //  std::cout<<"bb"<<pair.first<<"bb"<<sum;
            std::cout<<"\n";
            recent=pair.first;
            sum=0;
            //std::cout<<recent;
        }
    }

   /*     for(int i=0;i<data.size();i++){
            for(int j=0;j<data[i];j++)
                PrintUtility::print(color,"*");
            PrintUtility::print(color,"\n");

        }*/



}

Histogram::Histogram(const std::string &title, const std::vector<int> &data) : Graph(title, data) {}


