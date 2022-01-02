// 싸이클
// https://www.acmicpc.net/problem/2526

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int a, b, result = 0;
	vector<int> cycle;
	cin >> a >> b;
	cycle.push_back(a);
	while (true) {
		int c = cycle.back() * a % b;
		vector<int>::iterator pos = find(cycle.begin(), cycle.end(), c);
		if (pos == cycle.end())
			cycle.push_back(c);
		else {
			result = distance(pos, cycle.end());
			break;
		}
	}
	cout << result << endl;
}

// distance(begin, end) = 두 포인터 사이의 거리
// python의 indexof 대체 가능