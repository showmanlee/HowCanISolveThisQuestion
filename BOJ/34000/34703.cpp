// 공강 사수
// https://www.acmicpc.net/problem/34703

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<bool> visit(6);
	int cnt = 5;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (!visit[p]) {
			visit[p] = true;
			cnt--;
		}
	}
	cout << (cnt == 0 ? "NO" : "YES") << '\n';
}

// 평행사변형을 구성하는 맞닿은 두 선분이 주어질 때 두 선분에 포함되지 않는 점의 위치 구하기