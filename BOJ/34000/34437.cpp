// Number Reduction
// https://www.acmicpc.net/problem/34437

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	while (n > 1) {
		res++;
		if (n % 2 == 1) {
			n += n * 2 + 1;
		} else {
			n /= 2;
		}
	}
	cout << res << '\n';
}

// 짝수일 때 /2, 홀수일 때 +n*2+1을 반복해서 1로 만다는 연산 횟수 구하기