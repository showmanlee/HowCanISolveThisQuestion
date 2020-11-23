// 만취한 성범
// https://www.acmicpc.net/problem/6359

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		vector<bool> room(n + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j += i)
				room[j] = !room[j];
		}
		int res = 0;
		for (bool b : room)
			res += (b ? 1 : 0);
		cout << res << '\n';
	}
}

// n개의 방이 있는데, x번째 턴에 x의 배수 방의 잠금 상태를 달리한다면 n번째 턴 이후에는 몇 개의 방이 열려있을까?
// 어차피 100까지니 걍 반복으로?