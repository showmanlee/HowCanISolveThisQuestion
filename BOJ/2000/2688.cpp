// 줄어들지 않아
// https://www.acmicpc.net/problem/2688

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<vector<long long>> dp(65, vector<long long>(10));
    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= 64; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = j; k >= 0; k--) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        long long res = 0;
        for (int i = 0; i <= 9; i++) {
            res += dp[n][i];
        }
        cout << res << '\n';
    }
}

// 앞에 붙는 0을 포함해 앞자리가 뒷자리보다 크지 않은 n자리 수의 개수 구하기

// dp 문제 - 2차원으로 구성, i자리 수인데 맨 뒤가 j인 경우의 수 구하기
// 이 경우 i == 1일 경우 경우의 수는 언제나 1 - 근데 2 이상일 경우 i - 1 케이스 중 0~j까지의 케이스가 붙게 됨
// 이를 이용해 dp를 미리 계산하고, 들어오는 n에 따라 결과 출력하기