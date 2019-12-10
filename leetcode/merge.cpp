#include "merge.h"
#include <iostream>
using namespace std;

void merge() {
	//vector<vector<int>> v{ {1,3}, {8,10}, {2,6},{15,18} };
	vector<vector<int>> v{ {1,4},{4,10} };
	auto solver = Solution();
	auto re = solver.merge(v);
	for (auto i : re) {
		cout << i[0] << ' ' << i[1] << endl;
	}
}