#include "isMatch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void isMatch() {
	string s = "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbbb**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
	string p = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
	Solution solver;
	auto re = solver.isMatch(s,p);
	cout << re << endl;
}

