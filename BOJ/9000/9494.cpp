// Text Roll
// https://www.acmicpc.net/problem/9494

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<char, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    while (true) {
        string nn;
        getline(cin, nn);
        int n = stoi(nn);
        if (n == 0) {
            break;
        }
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            getline(cin, v[i]);
        }
        int x = 0, y = 0;
        while (true) {
            if (x >= n) {
                break;
            }
            if (v[x].length() > y && v[x][y] != ' ') {
                y++;
            } else if (v[x].length() <= y || v[x][y] == ' ') {
                x++;
            }
        }
        cout << (y + 1) << '\n';
    }
}

// 문자열 여러 줄의 가장 윗줄 왼쪽에 공을 놓고 오른쪽으로 기울일 떄, 바닥으로 떨어지는 열 번호 구하기