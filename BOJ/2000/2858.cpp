// 기숙사 바닥
// https://www.acmicpc.net/problem/2858

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int r, b;
    cin >> r >> b;
    int t = r + b;
    for (int i = 3; i * i <= t; i++) {
        if (t % i == 0) {
            int j = t / i;
            if ((i - 2) * (j - 2) == b) {
                cout << j << ' ' << i << '\n';
            }
        }
    }
}

// 2차원 보드의 가장자리에 두는 빨간 타일은 r개, 나머지 칸에 두는 갈색 타일은 b개 있을 때, 보드 크기가 얼마인지 구하기

// r + b = x * y, b = (x - 2) * (y - 2)
// 저 크기 안에서 나누어떨어지는 거 찾고 조건 맞춰보면 되는데 - 입력 조건상 최소 3*3 크기임이 보장됨