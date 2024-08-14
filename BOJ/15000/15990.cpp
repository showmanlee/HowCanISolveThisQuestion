// 1, 2, 3 더하기 5
// https://www.acmicpc.net/problem/15990

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<vector<long long>> v(100001, vector<long long>(4));
    v[1][1] = v[2][2] = v[3][1] = v[3][2] = v[3][3] = 1;
    for (int i = 4; i <= 100000; i++) {
        v[i][1] = (v[i - 1][2] + v[i - 1][3]) % 1000000009;
        v[i][2] = (v[i - 2][1] + v[i - 2][3]) % 1000000009;
        v[i][3] = (v[i - 3][1] + v[i - 3][2]) % 1000000009;
    }

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        long long res = (v[n][1] + v[n][2] + v[n][3]) % 1000000009;
        cout << res << '\n';
    }
}

// 어떤 자연수를 1, 2, 3의 합으로 나타낼 때 같은 수를 연속해서 사용하지 않는 경우의 수 출력하기

// dp는 2차원으로 세팅 - 어떤 수를 만드는데 사용한 마지막 숫자