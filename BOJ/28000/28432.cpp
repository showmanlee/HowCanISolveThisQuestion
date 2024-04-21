// 끝말잇기
// https://www.acmicpc.net/problem/28432

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> v(n);
    map<string, bool> visit;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        visit[v[i]] = true;
        if (v[i] == "?") {
            pos = i;
        }
    }
    int m;
    cin >> m;
    vector<string> w(m);
    for (int i = 0; i < m; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < m; i++) {
        if (pos != 0 && v[pos - 1].back() != w[i].front()) {
            continue;
        }
        if (pos != n - 1 && v[pos + 1].front() != w[i].back()) {
            continue;
        }
        if (!visit[w[i]]) {
            cout << w[i] << '\n';
            break;
        }
    }
}

// 중복 금지 끝말잇기 기록에서 하나가 빠진 결과가 주어질 때, 후보군 중 들어갈 수 있는 것 찾기