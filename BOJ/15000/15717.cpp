// 떡파이어
// https://www.acmicpc.net/problem/15717

#include <iostream>
#include <cmath>
using namespace std;

long long npow(long long b) {
	if (b == 0)
		return 1;
	long long p = npow(b / 2);
	long long ret = p * p % 1000000007;
	if (b % 2 == 1)
		ret = ret * 2 % 1000000007;
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	if (n == 0)
		cout << 1 << '\n';
	else
		cout << npow(n - 1) << '\n';
}

// 하루에 떡국을 하나 이상은 먹어야 하는 사람이 n개의 떡국을 먹었을 때, 떡국을 먹은 경우의 수(% 1000000007)는?

// n == 0 -> 0 = 1
// n == 1 -> 1 = 1
// n == 2 -> 2 11 = 2
// n == 3 -> 3 12 21 111 = 4
// n == 4 -> 4 13 22 31 112 121 211 1111 = 8 ...
// 따라서 이 문제는 2^(n-1)을 구하는 것과 같음 - 단 n == 0인 경우에는 1 출력
// 문제는 n이 10^12까지 주어질 수 있음 - pow나 for 기반의 제곱을 사용할 수 없음

// 이 문제의 답은 분할정복 - 분할정복(재귀) 기반으로 제곱을 수행하는 함수 만들기
// 지수를 매개변수로 접근 - b == 0이면 1 반환
// 그렇지 않다면 반환값은 npow(b / 2) ^ 2
// 만약 여기서 b가 홀수라면 여기서 2를 한번 더 곱해주고 반환