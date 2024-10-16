// 샷건
// https://www.acmicpc.net/problem/32371

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    map<char, pr> map;
    vector<vector<char>> board(4, vector<char>(10));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
            map[board[i][j]] = {i, j};
        }
    }
    int x = 0, y = 0;
    for (int i = 0; i < 9; i++) {
        char c;
        cin >> c;
        x += map[c].first;
        y += map[c].second;
    }
    x /= 9;
    y /= 9;
    cout << board[x][y] << '\n';
}

// 4*10 키보드 배열에서 3*3 영역 글자 9개가 무작위로 주어졌을 때, 중앙에 있는 글자 찾기

// 해당 글자들의 좌표값을 모두 더해 중앙값 찾기