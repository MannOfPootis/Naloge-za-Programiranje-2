//
// Created by doominik on 13.5.2024.
//

#ifndef NALOGA0901_MATRIX_H
#define NALOGA0901_MATRIX_H


#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    unsigned int rows;
    unsigned int cols;

public:
    Matrix(unsigned int rows, unsigned int cols);
    void setData(std::vector<std::vector<T>> newData);

    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
        for (const auto& row : matrix.data) {
            for (const auto& elem : row) {
                os << elem << " ";
            }
            os << "\n";
        }
        return os;
    };
    T &operator()(int x, int y){
        return data[y][x];
    }
    /*void operator = (T x){
      data[1][1]=x ;
    }*/
    Matrix& operator=(const Matrix&) & = default;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix& operator++();
    Matrix operator++(int);

    const std::vector<std::vector<T>> &getData() const;

    unsigned int getRows() const;

    void setRows(unsigned int rows);

    unsigned int getCols() const;

    void setCols(unsigned int cols);
};



#endif //NALOGA0901_MATRIX_H
