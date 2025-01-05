// 창고지기
// https://www.acmicpc.net/problem/31844

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < 10; i++) {
        if (s[i] == '@') {
            x = i;
        } else if (s[i] == '#') {
            y = i;
        } else if (s[i] == '!') {
            z = i;
        }
    }
    int res = 0;
    if (x < y && y < z) {
        res = z - x - 1;
    } else if (x > y && y > z) {
        res = x - z - 1;
    } else {
        res = -1;
    }
    cout << res << '\n';
}

// 1차원 공간에서 로봇이 상자를 밀어 목표까지 옮기는 최고 이동 수 구하기