#include "NumArray.h"

auto sumRange() -> int {
    vector<int> v{ 0,9,5,7,3 };
    auto na = NumArray(v);
    cout << na.sumRange(4, 4) << endl;
    cout << na.sumRange(2, 4) << endl;
    cout << na.sumRange(3, 3) << endl;

    na.update(1, 2);
    return 0;
}