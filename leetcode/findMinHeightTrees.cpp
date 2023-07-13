#include "findMinHeightTrees.h"
#include <iostream>
#include <vector>
using namespace std;

int findMinHeightTrees() {
	Solution s;
	//int n = 4;
	//vector<vector<int>> edges{{1, 0}, {1, 2}, {1, 3}};
	int n = 6;
	vector<vector<int>> edges{ {3, 0}, { 3, 1 }, { 3, 2 }, { 3, 4 }, { 5, 4 }};
	//int n = 6;
	//vector<vector<int>> edges{ {0, 1}, { 0, 2 }, { 0, 3 }, { 3, 4 }, { 4, 5 }};
	auto v = s.findMinHeightTrees(n, edges);
	for (auto i : v) {
		cout << i << ' ' << endl;
	}
	return 0;
}