#include "subsetsWithDup.h"

void subsetsWithDup() {
	vector<int> v{1,2,2};
	auto solver = Sol();
	auto re = solver.subsetsWithDup(v);
	for (auto i : re) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << endl;
	}
}
