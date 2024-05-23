//
// Created by doominik on 16.4.2024.
//

#ifndef NALOGA0701_POINT_H
#define NALOGA0701_POINT_H

#include <iostream>

class Point {
private:
    int x, y;
    static int lastX;
    static int lastY;

public:
    Point();
    Point(int x, int y);

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};


#endif //NALOGA0701_POINT_H
