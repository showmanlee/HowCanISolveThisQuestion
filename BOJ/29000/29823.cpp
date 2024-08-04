// Pakirobot Manhattanis
// https://www.acmicpc.net/problem/29823

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'N') {
            x++;
        } else if (c == 'S') {
            x--;
        } else if (c == 'E') {
            y++;
        } else if (c == 'W') {
            y--;
        }
    }
    int res = abs(x) + abs(y);
    cout << res << '\n';
}

// 2차원 격자 보드에서 이동한 경로가 주어질 때, 중앙과의 맨해튼 거리 구하기