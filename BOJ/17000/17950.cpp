// 스노우볼
// https://www.acmicpc.net/problem/17950

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int h;
	long long x;
	cin >> h >> x;
	vector<long long> v(h);
	for (int i = 0; i < h; i++) {
		cin >> v[i];
	}
	reverse(v.begin(), v.end());
	long long res = 0;
	for (int i = 0; i < h; i++) {
		res += v[i];
		res *= x;
		res %= 1000000007;
	}
	cout << res << '\n';
}

// 주어진 수들을 주어진 순서 및 횟수만큼 x를 곱해서 더한 결과 출력하기