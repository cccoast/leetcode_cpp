#include "next_permutaion.h"
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void nextPermutation() {
	//vector<int> v{ 2,2,7,5,4,3,2,2,1 };
	vector<int> v{ 2,1,2,2,2,2,2,1 };
	Solution solver;
	solver.nextPermutation(v);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}
