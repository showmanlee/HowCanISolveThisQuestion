// 투명
// https://www.acmicpc.net/problem/1531

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(101, vector<int>(101));
    for (int t = 0; t < n; t++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = a; i <= c; i++) {
            for (int j = b; j <= d; j++) {
                board[i][j]++;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (board[i][j] > m) {
                res++;
            }
        }
    }
    cout << res << '\n';
}

// 100*100 보드에서 특정 좌표 범위를 덮는 종이를 덮을 때, 종이가 m장 넘게 덮힌 칸의 수는?

// 100*100 배열을 이용해 각 칸에 덮힌 종이 수를 기억해두고, 마지막에 배열을 순회하며 m장 넘게 쌓인 칸을 세서 출력한다
// 1~100 범위