// 중복된 숫자
// https://www.acmicpc.net/problem/15719

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	long long res1 = n * (n - 1) / 2, res2 = 0;

	for (long long i = 0; i < n; i++) {
		long long p;
		cin >> p;
		res2 += p;
	}
	cout << (res2 - res1) << '\n';
}

// 1~n-1까지의 숫자가 정렬되지 않은 수열이 있고 거기에 1~n-1의 수 하나를 넣었다고 할 때, 그 수 구하기
// = 중복된 숫자 구하기
// 수열의 크기는 최대 1천만 - 배열로 체크할 수 없음
// 수열에 1~n-1까지의 수가 있기 때문에 (현재 수열의 합 - 1~n-1까지의 합)의 결과로 구할 수 있음