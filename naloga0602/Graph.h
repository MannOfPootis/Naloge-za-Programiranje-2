//
// Created by doominik on 11.4.2024.
//

#ifndef NALOGA0602_GRAPH_H
#define NALOGA0602_GRAPH_H
#include "PrintUtility.h"
#include "vector"
class Graph {
protected:
std::string title;
std::vector<int> data;
public:
    Graph(const std::string &title, const std::vector<int> &data);
    int GetmaxValue() const;
    int GetMinValue() const;
    void Show(ColorCode color) const ;
};


#endif //NALOGA0602_GRAPH_H
