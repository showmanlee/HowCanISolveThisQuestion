// Blocks
// https://www.acmicpc.net/problem/4349

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        int res = 987654321;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int k = n / i / j;
                if (i * j * k == n) {
                    int p = (i * j + j * k + k * i) * 2;
                    res = min(res, p);
                }
            }
        }
        cout << res << '\n';
    }
}

// 1*1*1 정육면체 n개를 직육면체 모양으로 쌓았을 때 표면적이 최소가 되는 경우 구하기

// 범위 안에서 두 변까지는 브루트포스가 가능함 - 마지막 변은 연산으로 체크하고 세 변의 길이로 직육면체를 만들 수 있으면 그걸로 표면적 계산