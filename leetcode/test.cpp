#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct three {
    int value;
    int index;
    int power;
};
bool xcmp(const three& a, const three& b) { return a.value > b.value; }
class Solution {
public:    
    void test() {
        vector<three> v{ {1,1,1},{2,1,1},{3,1,1},{4,1,1} };
        make_heap(v.begin(), v.end(), xcmp);
        for (auto i : v) {
            cout << i.value << ' ' << i.index << ' ' << i.power << endl;
        }
    }
};
int test() {
	
    auto s = Solution();
    s.test();
	return 0;
}