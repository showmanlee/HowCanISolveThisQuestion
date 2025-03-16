// 레몬 따기
// https://www.acmicpc.net/problem/28061

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		p = max(0, p - n + i - 1);
		res = max(res, p);
	}
	cout << res << '\n';
}

// 1~n+1 공간의 한 칸에서 수를 얻고 마지막칸으로 이동하면서 1칸에 1씩 빠질 때, 최대로 얻을 수 있는 수 구하기