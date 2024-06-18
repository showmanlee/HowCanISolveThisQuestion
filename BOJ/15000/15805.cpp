// 트리 나라 관광 가이드
// https://www.acmicpc.net/problem/15805

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(200000, -2);
    int cnt = 0;
    int prev = -1;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        cnt = max(cnt, p);
        if (v[p] == -2) {
            v[p] = prev;
        }
        prev = p;
    }
    cout << (cnt + 1) << '\n';
    for (int i = 0; i <= cnt; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

// 트리를 dfs로 순회한 경로가 주어질 떄, 각 트리 노드의 부모 노드 출력하기

// 처음으로 방문했을 경우, 바로 전 노드를 부모로 찍어준다