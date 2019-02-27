#include "dmp.hpp"
#include <iostream>
#include <string>

using namespace std;

using MyersStringDiff = MyersDiff<string>;

int main(int argn, char** args) {
    string one{"test"};
    string two{"text"};
    MyersStringDiff diff{one, two};

    for (const auto &i : diff) {
        cout << i.str() << endl;
    }

    return 0;
}
