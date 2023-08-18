// 점프는 즐거워
// https://www.acmicpc.net/problem/4383

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n) {
		vector<bool> v(n);
		int cnt = n - 1;
		int prev;
		cin >> prev;
		for (int i = 1; i < n; i++) {
			int p;
			cin >> p;
			int diff = abs(p - prev);
			if (diff < n && !v[diff]) {
				cnt--;
				v[diff] = true;
			}
			prev = p;
		}
		cout << (cnt == 0 ? "Jolly" : "Not jolly") << '\n';
	}
}

// 길이가 n인 정수 배열에서 연속된 두 수의 차의 절댓값이 1부터 n-1까지 모두 나오는지 확인하기

// 배열을 통해 기록하고, 카운팅으로 모두 지워졌는지 확인한다