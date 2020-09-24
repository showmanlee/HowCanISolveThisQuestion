// 나머지
// https://www.acmicpc.net/problem/3052

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> mod;
	int result = 0;
	for (int i = 0; i < 10; i++) {
		int n;
		cin >> n;
		if (find(mod.begin(), mod.end(), n % 42) == mod.end()) {
			result++;
			mod.push_back(n % 42);
		}
	}
	cout << result << endl;
}