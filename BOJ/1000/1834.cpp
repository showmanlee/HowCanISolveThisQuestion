// 나머지와 몫이 같은 수
// https://www.acmicpc.net/problem/1834

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	long long res = 0;
	for (long long i = 1; i < n; i++) {
		res += i * n + i;
	}

	cout << res << '\n';
}

// n으로 나눴을 때 몫과 나머지가 같은 수의 합은?

// 나머지는 0~n-1까지밖에 나올 수 없음 - 물론 나머지가 0인 경우의 답은 0이기에 의미는 없음
// 따라서 이 문제는 1부터 n-1까지 돌리면서 n * i + i의 합을 구하는 문제