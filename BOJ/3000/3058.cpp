// 짝수를 찾아라
// https://www.acmicpc.net/problem/3058

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> even;
		for (int j = 0; j < 7; j++) {
			int m;
			cin >> m;
			if (m % 2 == 0)
				even.push_back(m);
		}
		int sum = 0;
		sort(even.begin(), even.end());
		for (int j = 0; j < even.size(); j++)
			sum += even[j];
		cout << sum << " " <<  even[0] << endl;
	}
}