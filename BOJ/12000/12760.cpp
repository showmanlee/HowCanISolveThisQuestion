// 최후의 승자는 누구?
// https://www.acmicpc.net/problem/12760

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
        sort(v[i].begin(), v[i].end(), greater<int>());
    }
    vector<int> score(n);
    int res = 0;
    for (int j = 0; j < m; j++) {
        int maxx = 0;
        for (int i = 0; i < n; i++) {
            maxx = max(maxx, v[i][j]); 
        }
        for (int i = 0; i < n; i++) {
            if (v[i][j] == maxx) {
                score[i]++;
                res = max(res, score[i]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (score[i] == res) {
            cout << (i + 1) << ' ';
        }
    }
    cout << '\n';
}

// 동시에 숫자 카드를 내 가장 큰 수를 낸 사람(들)이 1점씩 얻는 게임을 n명이 m세트씩 할 때, 우승자(들) 구하기

// 중복 우승이 허용되므로 무조건 가장 높은 카드를 내는 게 이득
// 따라서 사람별로 덱을 내림차순으로 정렬하고, 차례로 내며 점수를 계산한 뒤 최대 점수를 기록한 사람들을 출력한다