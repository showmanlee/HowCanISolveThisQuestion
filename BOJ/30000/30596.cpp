// Axis-Aligned Area
// https://www.acmicpc.net/problem/30596

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
	sort(v.begin(), v.end());
	cout << (v[0] * v[2]) << '\n';
}

// 4개의 막대로 작사각형을 만들 때 최대로 만들 수 있는 면적 출력하기