#include "dmp.hpp"
#include<string>
#include <iostream>

using namespace std;

using dmp_str = DMP<string>;

int main (int argn, char** args) {

    dmp_str dmp;

    auto diff = dmp.diff_main("test", "text");

    for(auto i=diff.begin(); i!=diff.end(); ++i) {
        cout << i->str() << endl;
    }

    return 0;
}
