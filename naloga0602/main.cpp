#include <iostream>
#include "Histogram.h"
int main() {
    using namespace std::string_literals;
    system(("chcp "s + std::to_string(65001)).c_str());

    Histogram histogram("Histogram of results",std::vector<int>{5, 6, 10, 20, 16, 18, 9, 11, 12, 7, 7, 13});
    histogram.show(ColorCode::Blue,1);

    return 0;
}
