// 그르다 김가놈
// https://www.acmicpc.net/problem/18113

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, m;
	cin >> n >> k >> m;
	vector<int> v;
	int s = 0, e = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p >= k * 2) {
			p -= k * 2;
		} else if (p >= k) {
			p -= k;
		} else {
			p = 0;
		}
		e = max(e, p);
		if (p > 0) {
			v.push_back(p);
		}
	}
	int res = -1;
	int d = 0;
	while (s <= e) {
		d = (s + e) / 2;
		if (d == 0) {
			s++;
			continue;
		}
		int cnt = 0;
		for (int i : v) {
			cnt += i / d;
		}
		if (cnt >= m) {
			res = max(res, d);
			s = d + 1;
		} else {
			e = d - 1;
		}
	}
	cout << res << '\n';
}

// 길이가 다른 김밥 n개에서 꼬다리를 kcm씩 잘라서(2kcm 미만의 경우 한쪽만 자르고, kcm 미만의 경우 폐기), 몸통으로 길이가 같은 김밥 조각 m개 이상을 만들고 싶을 때, 얻을 수 있는 가장 긴 조각 길이 구하기

// 우선 조건에 맞게 꼬다리를 자른 김밥의 길이들을 구해 배열에 넣는다
// 들어갈 수 있는 길이가 10억이므로 전체 탐색은 불가능 - 이분탐색으로 배열 전체에 대해 얻을 수 있는 조각의 수를 구한다