// 회전하지 않는 캘리퍼스
// https://www.acmicpc.net/problem/30394

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int minn = 1987654321;
    int maxx = -1987654321;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        minn = min(y, minn);
        maxx = max(y, maxx);
    }
    cout << (maxx - minn) << '\n';
}

// 2차원 공간에 n개의 점이 있을 때, x축에서 가장 바깥쪽에 있는 두 점의 x축 거리 구하기

// 말 그대로