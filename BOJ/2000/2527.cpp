// 직사각형
// https://www.acmicpc.net/problem/2527

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int t = 0; t < 4; t++) {
        int ax, ay, bx, by, cx, cy, dx, dy;
        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

        int x = min(bx, dx) - max(ax, cx);
        int y = min(by, dy) - max(ay, cy);
        if (x > 0 && y > 0) {
            cout << 'a';
        } else if (x < 0 || y < 0) {
            cout << 'd';
        } else if (x == 0 && y == 0) {
            cout << 'c';
        } else {
            cout << 'b';
        }
        cout << '\n';
    }
}

// 2개의 직사각형이 주어질 떄, 서로 겹치는 부분 출력하기

// 가장 안쪽에 있는 점들을 모아서 직사각형을 그려보자 - 정확히는 안쪽에 있는 점들의 좌표 차를 구해보자
// 이 상황에서 좌표 차가 양수가 나오면 사각형으로 겹친다는 거, 음수면 안 겹친다는 거, 0이면 선으로 겹친다는 걸 의미
// 이를 이용해 풀어볼 수 있습니다