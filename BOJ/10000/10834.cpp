// 벨트
// https://www.acmicpc.net/problem/10834

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int dir = 0, speed = 1;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        speed = speed / a * b;
        if (c == 1) {
            dir = (dir + 1) % 2;
        }
    }
    cout << dir << ' ' << speed << '\n';
}

// 바퀴들이 순서대로 0자(정방향) 또는 8자(역방향) 벨트로 묶여 특정한 비율대로 회전할 때, 1번 바퀴를 1만큼 회전할 때 마지막 바퀴의 회전 방향과 속도는?

// 회전비는 현재 회전수 / 전축 회전수 * 후축 회전수로 계산하면 된다 - 그리고 이 과정의 결과는 항상 정수가 나오도록 되어 있음
// 그리고 8자(1) 벨트일 경우 회전 방향이 반대가 되고, 0자(0)일 경우 그대로 된다
// 이를 이용해 차례대로 벨트를 굴려가며 확인해봅시다