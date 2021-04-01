// 신나는 함수 실행
// https://www.acmicpc.net/problem/9184

#include <iostream>
using namespace std;

int dp[21][21][21];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);

	if (dp[a][b][c] != 0)
		return dp[a][b][c];

	if (a < b && b < c)
		dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

	return dp[a][b][c];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}
}

// 재귀 함수 w(a, b, c)의 출력값 출력하기
// 재귀를 dp로 만들라는 뜻
// dp 함수를 재귀 형태로 만들되, 이미 재귀한 결과가 dp에 있는 경우 dp를 출력, 그렇지 않다면 한번만 재귀 돌리기
// 테케가 많아질 수록 dp에 쌓이는 정보들이 많아지고, 이는 곧 다음 테케 실행을 더 빠르게 할 수 있음을 의미