// Cuboids
// https://www.acmicpc.net/problem/7581

#include <iostream>
#include <vector>
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
        } else if (a == 0) {
            cout << (d / b / c) << ' ' << b << ' ' << c << ' ' << d << '\n';
        } else if (b == 0) {
            cout << a << ' ' << (d / a / c) << ' ' << c << ' ' << d << '\n';
        } else if (c == 0) {
            cout << a << ' ' << b << ' ' << (d / a / b) << ' ' << d << '\n';
        } else if (d == 0) {
            cout << a << ' ' << b << ' ' << c << ' ' << (a * b * c) << '\n';
        }
    }
}

// 한 직육면체의, 가로, 세로, 높이, 부피 중 하나가 빠졌을 때, 빠진 값 채우기

// 위치를 보고 계산해서 넣어줍시다