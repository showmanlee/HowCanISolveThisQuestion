// ДИНИ
// https://www.acmicpc.net/problem/24312

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<int> v(4);
    for (int i = 0; i < 4; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int res = min(abs(v[0] - v[1] - v[2] - v[3]), min(abs(v[0] + v[1] + v[2] - v[3]), abs(v[0] + v[3] - v[1] - v[2])));
    cout << res << '\n';
}

// 주어진 4개의 수박을 양손에 들 때, 양손의 무게 차가 최소가 되도록 하는 경우의 무게 차 출력하기

// 손에 1-3개를 들 수도 있음