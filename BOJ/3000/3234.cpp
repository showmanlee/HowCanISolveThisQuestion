// LUKA
// https://www.acmicpc.net/problem/3234

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    
    int a, b, n;
    cin >> a >> b >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> res;
    int x = 0, y = 0;
    for (int i = 0; i <= n; i++) {
        if (s[i] == 'I') {
            x++;
        } else if (s[i] == 'S') {
            y++;
        } else if (s[i] == 'Z') {
            x--;
        } else if (s[i] == 'J') {
            y--;
        }
        if (a - 1 <= x && x <= a + 1 && b - 1 <= y && y <= b + 1) {
            res.push_back(i);
        }
    }
    if (res.empty()) {
        cout << -1 << '\n';
    } else {
        for (int i : res) {
            cout << i << '\n';
        }
    }
}

// 2차원 좌표에서 0,0에서 출발해 이동한 경로가 주어질 때, 주어진 칸 또는 그 주변 8방향 영역에 들어가는 시점 출력하기