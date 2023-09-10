// TV Reports
// https://www.acmicpc.net/problem/6249

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, c, r;
	cin >> n >> c >> r;
	for (int i = 0; i < n; i++) {
		int cc;
		cin >> cc;
		if (cc < c) {
			cout << "NTV: Dollar dropped by " << (c - cc) << " Oshloobs\n";
		} else if (cc > r) {
			cout << "BBTV: Dollar reached " << cc << " Oshloobs, A record!\n";
			r = cc;
		}
		c = cc;
	}
}

// Oshloobs의 현재 시세와 최고 시세가 주어질 때, 시세가 떨어졌을 경우 종전가보다 얼마나 떨어졌는지, 그리고 최고가를 경신했을 때 경신한 최고가 출력하기

// 말 그대로 그렇게 출력해주면 되는 문제