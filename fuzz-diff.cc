#include <string.h>
#include <string>
#include "dmp_diff.hpp"

using namespace std;

using MyersStringDiff = MyersDiff<string>;

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    uint8_t *at = (uint8_t*)memchr(Data, '\n', Size);
    string one, two;
    if (at) {
        size_t sz = at - Data;
        one.append((char*)Data, sz);
        two.append((char*)at+1, Size-sz-1);
    } else {
        one.append((char*)Data, Size);
    }
    MyersStringDiff diff{one, two};
    auto stats = diff.stats();
    assert(one.size()==stats.equal+stats.deleted);
    assert(two.size()==stats.equal+stats.inserted);
    return 0;
}
