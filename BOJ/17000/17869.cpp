// Simple Collatz Sequence
// https://www.acmicpc.net/problem/17869

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	int res = 0;
	while (true) {
		if (n == 1) {
			break;
		}
		if (n % 2 == 0) {
			n /= 2;
		} else {
			n++;
		}
		res++;
	}
	cout << res << '\n';
}

// 주어진 수가 짝수일 떼는 /2, 홀수일 때는 +1을 1이 될 때까지 반복할 때, 반복 횟수 구하기

// 직접 해보면 됩니다 - 결과가 부호 없는 32비트 정수형인데 +1을 할 수 있으므로 64비트에서 봐줘야 함