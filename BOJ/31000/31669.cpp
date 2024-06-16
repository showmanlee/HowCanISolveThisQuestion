// 특별한 학교 탈출
// https://www.acmicpc.net/problem/31669

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    int res = -1;
    for (int j = 0; j < m; j++) {
        res = j + 1;
        for (int i = 0; i < n; i++) {
            if (v[i][j] == 'O') {
                res = -1;
                break;
            }
        }
        if (res != -1) {
            break;
        }
    }
    if (res == -1) {
        cout << "ESCAPE FAILED\n";
    } else {
        cout << res << '\n';
    } 
}

// OX개 채워져 있는 n*m 보드에서 한 열에 모든 값이 X인 열 찾기