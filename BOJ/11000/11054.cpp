// 가장 긴 바이토닉 부분 수열
// https://www.acmicpc.net/problem/11054

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n + 2), dpp(n + 2), dpm(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				dpp[i] = max(dpp[i], dpp[j] + 1);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
		for (int j = n + 1; j > i; j--) {
			if (v[i] > v[j]) {
				dpm[i] = max(dpm[i], dpm[j] + 1);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dpp[i] + dpm[i] - 1);
    }
	cout << res << '\n';
}

// 주어진 수열의 부분 수열 중 가장 긴 '늘어났다 줄어드는 바이토닉 수열'의 길이 구하기

// 증가하는 가장 긴 수열 dp + 반대 방향에서 증가하는 가장 긴 수열 dp 더하기
// 다만 이렇게 구한 길이는 만나는 지점이 중복되므로 -1하기