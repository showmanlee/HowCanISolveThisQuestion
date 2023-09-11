// 저금
// https://www.acmicpc.net/problem/4998

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	double n, b, m;
	while (cin >> n) {
		cin >> b >> m;
		int res = 0;
		while (n <= m) {
			res++;
			n *= 1 + (b / 100);
		}
		cout << res << '\n';
	}
}

// n원이 입급된 계좌에 매년 b%의 이자가 들어올 때, m원이 되는데 걸리는 시간 구하기

// 직접 구해봅니다 - 반복문 돌려서?