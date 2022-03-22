// 녹색거탑
// https://www.acmicpc.net/problem/24723

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 1;
	for (int i = 0; i < n; i++) {
		res *= 2;
	}
	cout << res << '\n';
}


// 삼각형 형태로 쌓인 블록에서 인접한 두 아래 블록 중 하나를 밟고 내려갈 수 있을 때, 꼭대기에서 내려갈 수 있는 경우의 수는?

// 2^n