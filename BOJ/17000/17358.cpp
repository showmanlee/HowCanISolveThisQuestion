// 복불복으로 지구 멸망
// https://www.acmicpc.net/problem/17358

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	
	long long res = 1;
	for (long long i = 1; i <= n / 2; i++) {
		res *= (i * 2 - 1);
		res %= 1000000007;
	}
	cout << res << '\n';
}

// n(짝수) 개의 컵을 정확히 한 번씩 섞어 만들 수 있는 컵 순서의 경우의 수는?

// 2, 4, 6 순으로 1, 3, 15... 의 수열이 만들어진다
// 사실 이 문제는 어떤 컵 하나가 다른 컵 중 하나를 고르고, 남은 컵 중 하나가 다른 컵을 고르고... 이게 반복되는 상황
// 어떤 컵이 다른 컵을 고르는 경우는 n - 1가지, 그리고 컵 2개가 빠진다 - 1, 3 * 1, 5 * 3 * 1...
// 따라서 1부터 n/2까지 (i * 2 - 1)의 곱을 구하면 됨 - 1000000007 mod 잊지 말고