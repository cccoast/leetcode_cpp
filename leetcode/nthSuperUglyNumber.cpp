#include "nthSuperUglyNumber.h"

int main() {
	int n = 4;
	vector<int> primes{ 2, 7, 13, 19 };
	Solution s;
	cout << s.nthSuperUglyNumber(n, primes) << endl;
	return 0;
}