// 거리의 합
// https://www.acmicpc.net/problem/2399

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res += abs(v[i] - v[j]);
		}
	}
	cout << res << '\n';
}

// 1차원 좌표 내 점들에 대해 모든 쌍의 길이의 합 출력하기

// 점이 10000개까지 주어지고, 연산이 간단해서 n^2가 가능함
// 따라서 생각나는 대로 그려주면 됨