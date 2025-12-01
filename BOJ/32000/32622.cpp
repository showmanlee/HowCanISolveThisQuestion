// 카드 뒤집기 게임
// https://www.acmicpc.net/problem/32622

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v;
	v.push_back(0);
	int prev = -1, cnt = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (prev != p) {
			if (cnt != 0) {
				v.push_back(cnt);
			}
			cnt = 1;
			prev = p;
		} else {
			cnt++;
		}
	}
	v.push_back(cnt);
	v.push_back(1);
	int res = 0;
	if (v.size() == 3) {
		res = v[1];
	} else {
		for (int i = 1; i < v.size() - 1; i++) {
			res = max(res, v[i]);
			res = max(res, v[i] + v[i + 1]);
		}
	}
	cout << res << '\n';
}

// 주어진 카드 앞뒷면 상태에서 1번부터 1~n번 카드를 한번에 뒤집을 수 있을 때, 얻을 수 있는 최대 점수 구하기