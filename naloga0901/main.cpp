#include <iostream>
#include "Matrix.cpp"

/*template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<int>& matrix) {
    for (const auto& row : matrix.getData()) {
        for (const auto& elem : row) {
            os << elem << " ";
        }
        os << "\n";
    }
    return os;
}*/

int main() {
    Matrix<int> matrixA(2, 3);
    try{

        matrixA.setData({{1, 2, 3}, {4, 5, 6}});
    }catch (std::exception e) {
        std::cout<< e.what();
    }
    std::cout<<"lol";
    std::cout << "Matrix A:\n" << matrixA << std::endl;

    Matrix<int> matixB(2, 3);
    try{

        matixB.setData({{1, 1, 1}, {1, 1, 1}});
    }catch (std::exception e) {
        std::cout<< e.what();
    }
    matrixA(1,1)=10;
    std::cout << "Matrix B:\n" << matixB << std::endl;
    std::cout<<"test 1:"<<matrixA(1,1)<<"\n";
    std::cout << "Matrix B with postfix:\n" << matixB++ << std::endl;
    std::cout << "Matrix B with prefix:\n" << ++matixB << std::endl;

    // Matrix addition
    Matrix matrixC = matrixA + matixB;
    std::cout << "Matrix addition:\n" << matrixC << std::endl;

    // Matrix subtraction
    Matrix matrixD = matrixA - matixB;
    std::cout << "Matrix subtraction:\n" << matrixD << std::endl;
    return 0;
}
