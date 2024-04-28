// 나의 FIFA 팀 가치는?
// https://www.acmicpc.net/problem/29160

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<priority_queue<int>> v(12);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push(b);
    }
    for (int t = 0; t < k; t++) {
        for (int i = 1; i <= 11; i++) {
            if (!v[i].empty()) {
                int p = v[i].top();
                v[i].pop();
                v[i].push(p - 1);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= 11; i++) {
        if (!v[i].empty()) {
            res += v[i].top();
        }
    }
    cout << res << '\n';
}

// 1번부터 11번 슬롯에 능력치가 들어오고, 매년 말에 최대 능력치를 가진 사람 중 1명의 능력치가 1씩 깎일 때, k년 말에 능력치가 가장 높은 사람들 뽑기

// priority_queue 사용해보자