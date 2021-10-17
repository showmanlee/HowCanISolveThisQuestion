// 일우는 야바위꾼
// https://www.acmicpc.net/problem/20361

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x, k;
	cin >> n >> x >> k;
	vector<bool> cups(n + 1);
	cups[x] = true;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		swap(cups[a], cups[b]);
		if (cups[a]) {
			x = a;
		}
		if (cups[b]) {
			x = b;
		}
	}
	cout << x << '\n';
}

// n개의 컵 중 x번째 컵에 구슬을 넣고 k번 섞을 때, 구슬이 있는 컵 번호 구하기

// 컵을 나타내는 배열을 만들어 x번 컵에 구슬을 '넣은' 후, swap으로 섞기
// 만약 구슬이 담긴 컵이 움직였다면 현재 공의 위치를 갱신, 모든 swap이 끝나면 출력