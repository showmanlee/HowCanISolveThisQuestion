// Sounds fishy!
// https://www.acmicpc.net/problem/6764

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(4);
	for (int i = 0; i < 4; i++) {
		cin >> v[i];
	}
	if (v[0] < v[1] && v[1] < v[2] && v[2] < v[3]) {
		cout << "Fish Rising\n";
	} else if (v[0] > v[1] && v[1] > v[2] && v[2] > v[3]) {
		cout << "Fish Diving\n";
	} else if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3]) {
		cout << "Fish At Constant Depth\n";
	} else {
		cout << "No Fish\n";
	}
}

// 물고기 탐지기에서 연속된 네 개의 수가 증가하거나 감소하거나 일정할 때만 물고기가 있다 할 수 있을 때, 물고기가 있는지 판정하기

// 연속된 네 수를 구한 뒤, 서로 마주한 두 수의 관계가 모두 일정한지 확인한다