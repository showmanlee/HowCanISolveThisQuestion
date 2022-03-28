// Fergusonball Ratings
// https://www.acmicpc.net/problem/24569

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		int r = a * 5 - b * 3;
		if (r > 40) {
			cnt++;
		}
	}
	cout << cnt << (cnt == n ? "+" : "") << '\n';
}

// 득점과 파울이 각각 5점과 -3점의 가치를 가질 때, 도합 40점을 넘는 선수의 수와 주어진 모든 선수가 40점을 넘었는지 판정하기

// 각 선수마다 점수를 계산해보고 40점을 넘는 개수를 센다 - 이후 개수와 함께 그 개수가 n이라면 뒤에 + 붙이기