// 점프 점프
// https://www.acmicpc.net/problem/18512

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x, y, n, m;
    cin >> x >> y >> n >> m;
    bool pass = false;
    for (int i = 0; i < 1000; i++) {
        if (n < m) {
            n += x;
        } else if (n > m) {
            m += y;
        }
        if (n == m) {
            cout << n << '\n';
            pass = true;
            break;
        }
    }
    if (!pass) {
        cout << -1 << '\n';
    }
}

// 직선 공간에서 두 점의 출발점과 한번에 이동하는 거리가 주어질 떄, 가장 처음으로 만나는 지점 구하기

// 그대로 돌려보자