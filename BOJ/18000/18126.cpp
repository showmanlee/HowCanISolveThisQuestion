// 너구리 구구
// https://www.acmicpc.net/problem/18126

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, long long> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<pr>> board(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        board[a].push_back({b, c});
        board[b].push_back({a, c});
    }
    vector<long long> visit(n + 1, -1);
    visit[1] = 0;
    queue<int> q;
    q.push(1);
    long long res = 0;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (auto t : board[p]) {
            if (visit[t.first] == -1) {
                visit[t.first] = visit[p] + t.second;
                q.push(t.first);
                res = max(res, visit[t.first]);
            }
        }
    }
    cout << res << '\n';
}

// n개의 방이 길이가 서로 다른 n-1개의 길로 이어져 있을 때, 1번 방에서 가장 멀리 있는 방의 거리 구하기

// bfs로 1번씩 순회하면서 가장 먼 방 찾기