// 部員の変遷
// https://www.acmicpc.net/problem/32089

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int p = 0, res = 0;
        for (int i = 0; i < n; i++) {
            p += v[i];
            if (i >= 3) {
                p -= v[i - 3];
            }
            res = max(res, p);
        }
        cout << res << '\n';
    }
}

// 주어진 수열에서 연속된 3개의 수의 합이 가장 큰 경우 구하기