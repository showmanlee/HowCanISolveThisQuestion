// 경로 찾기
// https://www.acmicpc.net/problem/2479

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<string> v(n + 1);
    vector<vector<bool>> board(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        for (int j = 1; j < n; j++) {
            int cnt = 0;
            for (int l = 0; l < k; l++) {
                if (v[i][l] != v[j][l]) {
                    cnt++;
                }
            }
            if (cnt == 1) {
                board[i][j] = board[j][i] = true;
            }
        }
    }
    int s, e;
    cin >> s >> e;
    vector<int> prev(n + 1, -1);
    queue<int> q;
    q.push(s);
    prev[s] = 0;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        if (p == e) {
            break;
        }
        for (int i = 1; i <= n; i++) {
            if (p != i && board[p][i]) {
                if (prev[i] == -1) {
                    prev[i] = p;
                    q.push(i);
                }
            }
        }
    }
    if (prev[e] == -1) {
        cout << -1 << '\n';
    } else {
        vector<int> res;
        int idx = e;
        while (idx > 0) {
            res.push_back(idx);
            idx = prev[idx];
        }
        reverse(res.begin(), res.end());
        for (int i : res) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

// 같은 길이의 2진수로 구성된 배열이 주어질 떄, a에서 b까지 자릿수 차이가 1인 수를 통해서 이동하는 경로 구하기