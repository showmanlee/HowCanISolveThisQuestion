// 사이클 게임
// https://www.acmicpc.net/problem/20040

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pr;

int group[500001];

int finding(int p) {
    if (group[p] == p)
        return p;
    return group[p] = finding(group[p]);
}

void unioning(int a, int b) {
    int ga = finding(a), gb = finding(b);
    if (ga < gb)
        group[gb] = ga;
    else if (ga > gb)
        group[ga] = gb;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        group[i] = i;
    vector<pr> turns(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> turns[i].first >> turns[i].second;
    int res = 0;
    for (int i = 1; i <= m; i++) {
        int a = turns[i].first;
        int b = turns[i].second;
        if (finding(a) != finding(b))
            unioning(a, b);
        else {
            res = i;
            break;
        }
    }
    cout << res << '\n';
}

// n개의 점 사이에 선분을 긋는 과정을 반복할 때, 몇 번째 턴에서 사이클이 형성되는가?
// 사이클이 형성된다 = 같은 그룹의 점들이 다시 연결된다
// 따라서 union-find 기반으로 풀 수 있음
// 우선 모든 입력을 다 받아 이를 배열화한 후, 매 턴을 돌면서 두 그룹이 다른 곳에 있는지 확인
// 만약 다른 곳이라면 union하고, 같은 곳이라면 해당 턴에서 사이클이 형성되는 것