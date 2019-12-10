#include "groupAnagrams.h"
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void groupAnagrams() {
	vector<string> s{ "eat", "tea", "tan", "ate", "nat", "bat" };
	auto solver = Solution();
	auto ret = solver.groupAnagrams(s);
	for (auto v : ret) {
		for (auto s : v) {
			cout << s << " ";
		}
		cout << endl;
	}
}