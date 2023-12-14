// 판화
// https://www.acmicpc.net/problem/1730

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
    string s;
    cin >> s;
    vector<vector<bool>> xdir(n + 2, vector<bool>(n + 2)), ydir(n + 2, vector<bool>(n + 2));
    int x = 1, y = 1;
    for (char c : s) {
        if (c == 'U') {
            x--;
            if (x < 1) {
                x++;
            } else {
                xdir[x][y] = true;
                xdir[x + 1][y] = true;
            }
        } else if (c == 'D') {
            x++;
            if (x > n) {
                x--;
            } else {
                xdir[x][y] = true;
                xdir[x - 1][y] = true;
            }
        } else if (c == 'L') {
            y--;
            if (y < 1) {
                y++;
            } else {
                ydir[x][y] = true;
                ydir[x][y + 1] = true;
            }
        } else if (c == 'R') {
            y++;
            if (y > n) {
                y--;
            } else {
                ydir[x][y] = true;
                ydir[x][y - 1] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (xdir[i][j] && ydir[i][j]) {
                cout << '+';
            } else if (xdir[i][j]) {
                cout << '|';
            } else if (ydir[i][j]) {
                cout << '-';
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
}

// n*n 보드에서 좌측 상단부터 로봇 팔의 이동 경로가 주어질 때, 이동한 궤적 출력하기

// 위치가 아닌 방향을 체크해줘야 한다 - 따라서 수직/수평으로 지났는지를 따로 체크해줘야 함
// 보드 바깥으로 넘어가지 않도록 커서 이동하면서 수직/수평 이동 여부 체크하고, 이에 맞춰 출력하기