// 1, 2, 3 더하기
// https://www.acmicpc.net/problem/9095

#include <iostream>
using namespace std;

int main(void) {
    int dp[11];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 10; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}

// 1 - 1 : 1
// 2 - 2 11 : 2
// 3 - 111 12 21 3 : 4
// 4 - 1111 112 121 211 22 13 31 : 7
// 5 - 11111 1112 1121 1211 2111 122 212 221 113 131 311 23 32 : 13
// 이런 문제의 대부분은 피보나치의 변형 - 최댓값도 10이니 부담없음