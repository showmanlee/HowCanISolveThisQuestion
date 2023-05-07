// 첨탑 밀어서 부수기
// https://www.acmicpc.net/problem/28014

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 1;
	int prev = 987654321;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (prev <= p) {
			res++;
		}
		prev = p;
	}
	cout << res << '\n';
}

// 일렬로 세워진 첨탑을 왼쪽부터 넘어뜨리는 상황에서 넘어진 첨탑이 바로 옆 첨탑보다 크면 같이 넘어질 때, 모든 첨탑을 넘어뜨리기 위해 넘어뜨려야 하는 첨탑의 수 구하기

// 왼쪽부터 순회하며 이전 첨탑이 다읍 첨탑보다 작거나 같으면 횟수를 늘린다