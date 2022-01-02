// 파스칼의 삼각형
// https://www.acmicpc.net/problem/16395

#include <iostream>
using namespace std;

int main(void) {
	int dp[30][30];
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	int n, k;
	cin >> n >> k;
	cout << dp[n - 1][k - 1] << '\n';
}

// 파스칼의 삼각형에서 n번째 행 k번째 수 구하기
// 파스칼의 삼각형에 있는 숫자는 곧 (n-1)C(k-1)와 같음
// nCk = n! / k!(n-k)! (nPk = n! / (n-k)!)
// 하지만 지금 이 상황에서는 직접 파스칼의 삼각형을 만들어가며 풀 수 있음 - 팩토리얼끼리 곱하고 나누면 오버플로 발생하기도 하고