// 하키
// https://www.acmicpc.net/problem/1358

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int w, h, x, y, n;
    cin >> w >> h >> x >> y >> n;
    int res = 0;
    int lx = x - h / 2;
    int rx = x + w + h / 2;
    int ty = y + h;
    int cy = y + h / 2;
    for (int i = 0; i < n; i++) {
        int px, py;
        cin >> px >> py;
        if (px < lx || px > rx || py < y || py > ty) {
            continue;
        }
        if (px >= x && px <= (x + w) && py >= y && py <= ty) {
            res++;
        } else if (px < x || px > (x + w)) {
            int ppx = px - (px < x ? x : x + w);
            int ppy = py - cy;
            if (ppx * ppx + ppy * ppy <= (h / 2) * (h / 2)) {
                res++;
            }
        }
    }
    cout << res << '\n';
}

// (x, y)에서 가로 w, 세로 h의 직사각형과 양옆에 h/2를 반지름으로 하는 반원 2개가 붙은 형태의 하키장이 있을 때, 선수들의 좌표를 보고 몇 명이 하키장 안에 있는지 판정하기

// 도형의 방정식들을 조합해서 구해봅시다 