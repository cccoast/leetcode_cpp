#include "groupAnagrams.h"
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void groupAnagrams() {
	vector<string> s{ "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution solver;
	auto ret = solver.groupAnagrams(s);
	for (auto v : ret) {
		for (auto s : v) {
			cout << s << " ";
		}
		cout << endl;
	}
}