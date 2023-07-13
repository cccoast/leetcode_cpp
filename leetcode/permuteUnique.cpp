#include "permuteUnique.h"
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void permuteUnique() {
	vector<int> v{ 1,1,2 };
	Solution solver;
	auto re = solver.permuteUnique(v);
	for (auto i : re) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << endl;
	}
}