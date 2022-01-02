// 피시방 알바
// https://www.acmicpc.net/problem/1453

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<bool> seats(101);
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (seats[p])
			res++;
		else
			seats[p] = true;
	}
	cout << res << '\n';
}

// 100개의 좌석이 있는 피시방에 손님들이 특정 좌석을 원할 때, 그 좌석에 앉을 수 없는 사람의 수는?
// 번호를 요구한 첫 사람만 앉을 수 있다 - bool 배열 활용하기