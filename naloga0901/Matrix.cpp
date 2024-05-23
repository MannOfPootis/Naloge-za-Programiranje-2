//
// Created by doominik on 13.5.2024.
//

#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols) : rows(rows), cols(cols) {
    data.resize(rows, std::vector<T>(cols, 0));
}

template<typename T>
void Matrix<T>::setData(std::vector<std::vector<T>> newData) {
    if (newData.size() != rows || newData[0].size() != cols) {
        throw std::invalid_argument("Invalid dimensions for setData");
    }
    data = newData;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
    for (const auto& row : matrix.getData()) {
        for (const auto& elem : row) {
            os << elem << " ";
        }
        os << "\n";
    }
    return os;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Invalid dimensions for operator+");
    }
    Matrix result(rows, cols);
    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Invalid dimensions for operator-");
    }
    Matrix result(rows, cols);
    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator++() {
    for (auto& row : data) {
        for (auto& elem : row) {
            ++elem;
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator++(int) {
    Matrix<T> temp(*this);
    ++(*this);
    return temp;
}
