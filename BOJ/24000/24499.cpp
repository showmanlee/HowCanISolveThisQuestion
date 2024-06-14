// blobyum
// https://www.acmicpc.net/problem/24499

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
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i < k) {
            sum += v[i];
        }
    }
    int res = sum;
    for (int i = 0; i < n; i++) {
        sum -= v[i];
        sum += v[(i + k) % n];
        res = max(res, sum);
    }
    cout << res << '\n';
}

// 원형으로 놓인 파이의 맛 척도가 주어질 때, 연속으로 이어진 k개를 먹어 얻을 수 있는 가장 높은 척도 합 구하기

// 흔한 슬라이딩 윈도우 문제 - 그런데 윈도우가 원형인