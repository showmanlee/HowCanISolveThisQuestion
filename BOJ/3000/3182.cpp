// 한동이는 공부가 하기 싫어!
// https://www.acmicpc.net/problem/3182

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> board(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> board[i];
    }
    int res = 0, cnt = 0;
    for (int t = 1; t <= n; t++) {
        int p = t, c = 0;
        vector<bool> visit(n + 1);
        while (!visit[p]) {
            visit[p] = true;
            c++;
            p = board[p];
        }
        if (c > cnt) {
            res = t;
            cnt = c;
        }
    }
    cout << res << '\n';
}

// n명의 사람이 각각 알고 있는 다른 사람 1명이 주어질 때, 네트워크를 타고 가장 많이 만날 수 있는 사람 구하기

// 한 사람씩 집고 다시 보는 사람이 나올 떄까지 네트워크를 타면서 인원수를 센다