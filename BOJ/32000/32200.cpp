// 항해
// https://www.acmicpc.net/problem/32200

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, x, y;
    cin >> n >> x >> y;
    if (y / x >= 2) {
        y = x * 2 - 1;
    }
    int resa = 0, resb = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        resa += v[i] / x;
        resb += max(0, v[i] % x - (y - x) * (v[i] / x));
    }
    cout << resa << '\n' << resb << '\n';
}

// 길이가 다른 샌드위치들을 xcm 이상 ycm 이하로 잘라 먹을 때, 나눠먹을 수 있는 최대 양과 버리는 최소 양 구하기

// 가장 짧은 길이로 나눈 다음에 나머지는 각 조각에 균등하게 분배, 짧은 길이 * 2 - 1 또는 긴 길이의 최소까지 붙이기