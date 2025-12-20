// Пары
// https://www.acmicpc.net/problem/27272

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
	int res = (v[0] * v[1]) + (v[2] * v[3]);
	cout << res << '\n';
}

// 네 수를 2개씩 쪼개서 쌍의 곱의 합이 최대가 되는 경우 출력하기