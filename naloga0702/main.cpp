#include <vector>
#include "VectorUtil2.h"
#include "Point.h"

using namespace std;

int main() {
    using namespace std::string_literals;
    system(("chcp "s + std::to_string(65001)).c_str());
    vector<Point> listPoints;
    cout << " --- Default generator of 3 objects --- " << endl;
    fillDefault(listPoints, 3);
    std::vector<int> box;
    fillDefault(box, 20);
    std::vector<std::vector<int>> sus;
    sus = slice(box, 4);
    for(int i=0;i<sus.size();i++){
        for(int j =0;j<sus[i].size();j++){
            std::cout<<sus[i][j];
        }
        std::cout<<"\n";
    }

    vector<float> listFloats = {1.1f, 2.2f, 3.3f};
    vector<Point> pnts= cast(listFloats);
    std::cout<<"chek this out\n";
    print(pnts);
    printColor(box,ColorCode::Green);

    std::cout<<"dahubdougba";
    vector<float> listFloats2 = reverse(listFloats);
    cout << " --- Reverse: --- " << endl;
    print(listFloats2);

    cout << " --- To int vector: --- " << endl;
    print(toInt(listPoints));

    vector<std::string> listStrings = {"2", "asd", "34"};
    cout << " --- To int vector: --- " << endl;
    print(toInt(listStrings));

    vector<int> listInt;
    cout << " --- Default generator of 3 objects --- " << endl;
    fillDefault(listInt, 3);
    print(listInt);
    return 0;
}
