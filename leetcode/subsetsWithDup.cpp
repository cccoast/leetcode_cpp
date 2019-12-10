#include "subsetsWithDup.h"

void subsetsWithDup() {
	vector<int> v{ 1,1,2};
	auto solver = Solution();
	auto re = solver.subsetsWithDup(v);
	for (auto i : re) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << endl;
	}
}