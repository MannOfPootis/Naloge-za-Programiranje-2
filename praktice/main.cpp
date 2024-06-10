#include <iostream>
int sum(int i ){
    return i;
}
template<typename ... Args>
int sum(int i, Args... args){
    return i+sum(args...);
}
int main() {
    std::cout << "Hello, World!" <<sum(1,2,2,2,2,2,2,2,2,1)<< std::endl;
    return 0;
}