// 쿠키애호가
// https://www.acmicpc.net/problem/11134

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int a, b;
		cin >> a >> b;
		cout << (a / b + (a % b > 0 ? 1 : 0)) << '\n';
	}
}

// 총 a개의 쿠키를 매일 b개씩 먹다가 b개 미만 남았을 때는 다 먹을 때, 며칠 동안 쿠키를 먹을 수 있는지 출력하기

// 기본적으로 a / b, 이후 쿠키가 b개 미만으로 남는다면 - a % b > 0이라면 1일 추가