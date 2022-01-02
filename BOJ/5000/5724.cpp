// 파인만
// https://www.acmicpc.net/problem/5724

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		int res = 0;
		for (int i = 1; i <= n; i++)
			res += i * i;
		cout << res << '\n';
	}
}

// n*n 보드에서 존재할 수 있는 정사각형의 개수는?
// 1*1 ~ n*n까지의 합(n*n 사각형 1개 + n-1*n-1 사각형 2*2개 + ... + 2*2 사각형 n-1*n-1개 + 1*1 사각형 n*n개)