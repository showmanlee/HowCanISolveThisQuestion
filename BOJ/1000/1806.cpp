// 부분합
// https://www.acmicpc.net/problem/1806

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, s;
    cin >> n >> s;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int f = 0, r = 0;
    int res = 987654321, sum = v[0];
    while (r < n) {
        if (sum >= s) {
            res = min(res, r - f + 1);
        }
        if (f == r || sum <= s) {
			r++;
			sum += v[r];
		} else {
			sum -= v[f];
			f++;
		}
    }
    if (res == 987654321) {
        res = 0;
    }
    cout << res << '\n';
}

// 크기가 n인 수열에서 연속된 수들의 합이 s 이상인 경우 중 가장 짧은 경우 출력하기

// 투 포인터 응용해서 풀어주면 되는데 - 딱 s가 아니라 s 이상임에 주의