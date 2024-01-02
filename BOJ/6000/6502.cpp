// 동혁 피자
// https://www.acmicpc.net/problem/6502

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int cnt = 0;
    while (true) {
        cnt++;
        double r;
        cin >> r;
        if (r == 0) {
            break;
        }
        double w, h;
        cin >> w >> h;
        double d = sqrt(w * w + h * h);
        cout << "Pizza " << cnt << (d > r + r ? " does not fit" : " fits") << " on the table.\n";
    }
}

// 반지름이 r인 원형 테이블에 가로 w, 세로 h 길이의 사각형 피자가 넘치지 않고 들어가는지 판정하기

// 대각선 길이를 구한 후 지름과 비교해본다