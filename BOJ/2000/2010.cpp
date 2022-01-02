// 플러그
// https://www.acmicpc.net/problem/2010

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int remain = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		remain += p;
		remain--;
	}
	remain++;
	cout << remain << '\n';
}

// 한 개의 콘센트와 n개의 멀티탭이 있을 때, 꽂을 수 있는 최대 플러그 수는?
// 멀티탭의 모든 콘센트 합 - 멀티탭을 연결하는데 소모된 콘센트 수 + 소스에 연결한 콘센트 하나