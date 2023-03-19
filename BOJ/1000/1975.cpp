// Number Game
// https://www.acmicpc.net/problem/1975

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		int res = 0;
		for (int i = 2; i <= n; i++) {
			int p = n;
			while (p % i == 0) {
				res++;
				p /= i;
			}
		}
		cout << res << '\n';
	}
}

// 주어진 수를 2~x진법까지 나타냈을 떄 맨 뒤부터 연속되는 0의 개수 합 구하기

// 뒷자리가 0이 나온다는 건 n^x으로 나누어떨어진다는 뜻
// 따라서 n진수에서 p % n이 0일 때 결과 누적하고 p /= n하여 연속된 수를 구해본다
// n+1진법 이후로는 언제나 'n'의 형태가 되므로 무시