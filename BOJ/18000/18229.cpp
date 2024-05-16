// 내가 살게, 아냐 내가 살게
// https://www.acmicpc.net/problem/18229

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<int> res(n);
    bool done = false;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            res[i] += v[i][j];
            if (res[i] >= k) {
                cout << (i + 1) << ' ' << (j + 1) << '\n';
                done = true;
                break;
            }
        }
        if (done) {
            break;
        }
    }
}

// n명이 m번에 걸쳐 순서대로 손을 뻗는 거리가 주어질 떄, 먼저 닿는 사람 및 움직인 횟수 구하기

// 배열 순회하며 확인