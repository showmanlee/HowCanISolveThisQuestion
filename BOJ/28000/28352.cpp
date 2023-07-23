// 10!
// https://www.acmicpc.net/problem/28352

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 6;
	for (int i = 11; i <= n; i++) {
		res *= i;
	}
	cout << res << '\n';
}

// 10!초가 6주와 같을 때, n!초가 몇 주인지 판정하기
// n의 범위는 10~17 - 이미 10!으로 딱 몇 주인지 판정할 수 있게 됨
// 따라서 6에 11~n을 곱해 출력하면 그게 답