// 1로 만들기 2
// https://www.acmicpc.net/problem/12852

#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001], previous[1000001];

int main(void) {
    int n;
    cin >> n;
    dp[1] = 0;
    previous[1] = -1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        previous[i] = i - 1;
        if (i % 2 == 0) {
            if (dp[i] > dp[i / 2] + 1) {
                dp[i] = dp[i / 2] + 1;
                previous[i] = i / 2;
            }
        }
        if (i % 3 == 0) {
            if (dp[i] > dp[i / 3] + 1) {
                dp[i] = dp[i / 3] + 1;
                previous[i] = i / 3;
            }
        }
    }
    cout << dp[n] << '\n';
    int p = n;
    while (p != -1) {
        cout << p << ' ';
        p = previous[p];
    }
    cout << '\n';
}

// x % 3 == 0일 때 x / 3, x % 2 == 0일 때 x / 2, x - 1 연산으로 1을 만드는 연산의 최소 횟수와 그 과정 출력하기
// dp로 접근 - dp에는 그 수까지 들어가야 하는 연산의 횟수 기록
// n부터 1까지가 아닌, 1부터 n까지 과정을 추가하는 방식으로 접근하기
// 2부터 n까지 순회하면서 기본적으로 -1 연산을 한 결과를 저장하고, 이후 나누어떨어지는 수에 따라 갱신해야 되는 상황일 때만 갱신
// 또한 갱신되는 순간마다 이전 수를 기록하는 배열에 해당 수를 저장, 나중에 출력할 수 있게 함