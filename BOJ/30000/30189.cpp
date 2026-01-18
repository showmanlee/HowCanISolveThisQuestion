// 경우의 수의 합
// https://www.acmicpc.net/problem/30189

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int res = 0;
	for (int i = 0; i <= n + m; i++) {
		for (int a = 0; a <= i; a++) {
			int b = i - a;
			if (0 <= a && a <= n && 0 <= b && b <= m) {
				res++;
			}
		}
	}
	cout << res << '\n';
}

// 0~n+m을 각각 0~n, 0~m의 순서쌍으로 표현한 결과의 개수 출력하기