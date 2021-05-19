// 캠핑
// https://www.acmicpc.net/problem/4796

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t = 1;
	while (true) {
		int l, p, v;
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0)
			break;
		int res = v / p * l + (v % p > l ? l : v % p);
		cout << "Case " << t << ": " << res << '\n';
		t++;
	}
}

// 캠핑장이 연속된 p일 동안 l일만 쓸 수 있을 때, v일 휴가에서 캠핑장을 사용할 수 있는 날 수는?
// p일 중 l일만 사용할 수 있다는 건 기본적으로 v/p번의 l일동안 쓸 수 있다는 것을 의미 - l일을 지내기 위해 p일이 소모됨
// 문제는 v/p 이후 나머지 처리 - 남은 기간 동안은 얼마나 지낼 수 있는가?
// 만약 나머지가 l 이하면 남은 기간 동안 지낼 수 있음 - 어쨌든 새로운 연속된 p일이 시작되었으므로
// 그렇지 않다면 l일 동안 지낼 수 있음 - 연속된 p-a일이지만 그 동안 사용할 수 있는 날은 l일뿐

// 문제를 이해하자