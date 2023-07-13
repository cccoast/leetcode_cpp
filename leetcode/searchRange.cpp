
#include "searchRange.h"
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void searchRange() {
	Solution solver;
	auto array = vector<int>{ 5,7,7,8,8,10 };
	int target = 8;
	auto v = solver.searchRange(array, 8);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	return;
}

