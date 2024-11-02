// RICE SACK
// https://www.acmicpc.net/problem/9699

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = 0; j < 5; j++) {
            int p;
            cin >> p;
            res = max(res, p);
        }
        cout << "Case #" << i << ": " << res << '\n';
    }
}

// 주어질 배열에서 가장 높은 값 찾기 