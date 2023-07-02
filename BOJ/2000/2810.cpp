// 컵홀더
// https://www.acmicpc.net/problem/2810

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	bool skip = false;
	int cnt = 1;
	for (char c : s) {
		if (skip) {
			skip = false;
			continue;
		}
		cnt++;
		if (c == 'L') {
			skip = true;
		}
	}
	cout << min(cnt, n) << '\n';
}

// 일반석(S), 커플석(LL) 양옆에 컵홀더를 놓을 때, 컵을 놓을 수 있는 좌석의 수 구하기

// 커플석은 두 좌석이 서로 붙어있고, 사이에 컵홀더를 놓을 수 없음 - 나머지 좌석은 사이에 컵홀더 하나를 놓을 수 있고, 양 끝에도 컵홀더를 놓을 수 있음
// 규칙을 보면, 현재 좌석 왼쪽에 컵홀더를 놓고 마지막 좌석 오른쪽에 컵홀더를 하나 더 놓을 수 있음
// 이렇게 놓은 컵홀더 수와 좌석 수 중 더 작은 쪽이 답