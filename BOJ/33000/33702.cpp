// 비밀번호
// https://www.acmicpc.net/problem/33702

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	if (n % 2 == 0) {
		res = 0;
	} else {
		res = 8;
	}
	cout << res << '\n';
}

// 3*3 보드에서 출발점이 주어질 때, 상하좌우로 이동해서 모든 칸을 찍는 경우의 수 구하기