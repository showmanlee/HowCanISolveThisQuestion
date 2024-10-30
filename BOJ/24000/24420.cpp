// ピアノコンクール (Piano Competition)
// https://www.acmicpc.net/problem/24420

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        res += v[i];
    }
    sort(v.begin(), v.end());
    res -= v[0] + v[n - 1];
    cout << res << '\n';
}

// 주어진 정수들 중 최솟값과 최댓값을 뺀 나머지 수들의 합 구하기