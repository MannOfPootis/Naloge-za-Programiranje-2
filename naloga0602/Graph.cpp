//
// Created by doominik on 11.4.2024.
//

#include "Graph.h"

Graph::Graph(const std::string &title, const std::vector<int> &data) : title(title), data(data) {}

void Graph::Show(ColorCode color) const {
    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[i]-1;j++)
            PrintUtility::print(color," ");
        PrintUtility::print(color, "*");
    }

}

int Graph::GetmaxValue() const {
    int val= data[0];
    for(int i=0;i<data.size();i++){
        if(data[i]>val){
            val=data[i];
        }
    }
    return val;
}
int Graph::GetMinValue() const {
    int val= data[0];
    for(int i=0;i<data.size();i++){
        if(data[i]<val){
            val=data[i];
        }
    }
    return val;
}
