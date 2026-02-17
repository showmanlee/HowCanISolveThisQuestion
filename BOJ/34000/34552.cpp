// 디딤돌 장학금
// https://www.acmicpc.net/problem/34552

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(11);
	for (int i = 0; i < 11; i++) {
		cin >> v[i];
	}
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int b, s;
		double l;
		cin >> b >> l >> s;
		if (l >= 2.0 && s >= 17) {
			res += v[b];
		}
	}
	cout << res << '\n';
}

// 17학점 및 평점 2.0 이상인 학생에게 분위에 따라 주어진 만큼 장학금을 줄 때, 총 장학금 액수 구하기