//
// Created by doominik on 11.4.2024.
//

#ifndef NALOGA0602_HISTOGRAM_H
#define NALOGA0602_HISTOGRAM_H

#include <string>
#include <vector>
#include "Graph.h"
#include "map"
class Histogram:Graph {

public:

    void show(ColorCode color,int res) const;

    Histogram(const std::string &title, const std::vector<int> &data);
};


#endif //NALOGA0602_HISTOGRAM_H
