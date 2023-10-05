// 영화 평가
// https://www.acmicpc.net/problem/23278

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	cout << fixed;
    cout.precision(16);

	int n, l, h;
	cin >> n >> l >> h;
	vector<double> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	double res = 0;
	int cnt = n - l - h;
	for (int i = l; i < n - h; i++) {
		res += v[i];
	}
	res /= cnt;
	cout << res << '\n';
}

// 주어진 점수들에서 최저치 l개와 최고치 h개를 뺀 나머지 점수들의 평균 구하기

// 정렬하고 빼서 구해봅니다