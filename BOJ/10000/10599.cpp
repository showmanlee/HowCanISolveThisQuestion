// 페르시아의 왕들
// https://www.acmicpc.net/problem/10599

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (true) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == 0 && b == 0 && c == 0 && d == 0) {
            break;
        }
        cout << (c - b) << ' ' << (d - a) << '\n';
    }
}

// 출생연도 범위와 사망연도 범위가 주어질 때, 최소/최대 나이 구하기

// 구해봐요 - 최대 - 최소와 최소 - 최대