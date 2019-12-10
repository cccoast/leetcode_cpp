#include <string>
#include <regex>
#include <iostream>
using namespace std;
void isMatch();
class Solution {
public:
	bool isMatch(string s, string p) {
		std::regex regstar("(\\*+)");
		p = std::regex_replace(p, regstar, R"([a-z]*)");
		cout << p << endl;
		std::regex regques("(\\?)");
		p = std::regex_replace(p, regques, R"([a-z])");
		cout << p << endl;
		std::regex r(p);
		bool v = std::regex_match(s, r);
		return v;
	}
};