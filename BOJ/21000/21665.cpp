// Миша и негатив
// https://www.acmicpc.net/problem/21665

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == board[i][j]) {
                res++;
            }
        }
    }
    cout << res << '\n';
}

// 주어진 2차원 문자 배열 2개의 서로 같은 문자 개수 세기

// 정확히 말하면 두 가지 문자(BW)가 나올 수 있는 문자 배열을 반전했을 때 반전되지 않은 문자 수를 찾는 문제긴 하지만
// 첫 문자 배열은 배열에 저장하고, 두 번째 문자 배열은 위치만 보면서 같은지 확인하기