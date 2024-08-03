// The Game of Death
// https://www.acmicpc.net/problem/11558

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        vector<int> dir(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> dir[i];
        }
        vector<bool> visit(n + 1);
        int idx = 1;
        int res = 0;
        while (true) {
            visit[idx] = true;
            idx = dir[idx];
            res++;
            if (visit[idx]) {
                res = 0;
                break;
            } else if (idx == n) {
                break;
            }
        }
        cout << res << '\n';
    }
}

// n명이 1명씩 지목하는 상황에서 1번에서 n번으로 가는데 몇 단계가 필요한지 구하기

// n번을 만나기 전에 이미 본 사람을 봤다면 사이클이 걸린 거니 바로 탈출