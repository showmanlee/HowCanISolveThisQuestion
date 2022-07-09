// 수열
// https://www.acmicpc.net/problem/2559

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int res = -987654321;
    int sum = 0;
    for (int i = 0; i < k - 1; i++) {
        sum += v[i];
    }
    for (int i = k - 1; i < n; i++) {
        sum += v[i];
        res = max(sum, res);
        sum -= v[i - k + 1];
    }
    cout << res << '\n';
}

// 주어진 수열의 연속뒨 k개의 수의 합이 가장 큰 경우는?

// n^2로 구할 수 없으니 슬라이딩 윈도우로 한칸 움직일 때마다 맨 뒤 칸을 빼주는 방식으로 구한다
// 음수도 등장할 수 있기에, res 초기값을 0으로 두면 문제가 발생함에 주의