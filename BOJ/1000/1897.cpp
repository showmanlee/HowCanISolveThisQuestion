// 토달기
// https://www.acmicpc.net/problem/1897

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<string, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    string ss;
    cin >> n >> ss;
    vector<string> words(n);
    map<string, int> dist;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        dist[words[i]] = -1;
    }
    dist[ss] = 0;
    queue<pr> q;
    q.push({ss, 0});
    string res;
    while(!q.empty()) {
        string s = q.front().first;
        int p = q.front().second;
        q.pop();
        if (res.length() < s.length()) {
            res = s;
        }
        for (string& t : words) {
            if (dist[t] != -1) {
                continue;
            }
            if (s.length() + 1 == t.length()) {
                int idx = 0;
                for (char c : t) {
                    if (c == s[idx]) {
                        idx++;
                        if (idx == s.length()) {
                            break;
                        }
                    }
                }
                if (idx == s.length()) {
                    dist[t] = p + 1;
                    q.push({t, dist[t]});
                }
            }
        }
    }
    cout << res << '\n';
}

// 주어진 문자열에서 한 글자를 붙이거나 끼우는 방식으로 문자열을 늘려나가는 상황에서 사전에 주어진 문자열로만 갈 수 있을 때, 얻을 수 있는 최대 길이 문자열은?

// map으로 visit/dist를 찍으며, bfs로 확장해나간다
// 다음 문자열이 되는지는 그 문자열의 모든 문자를 탐색해야 알 수 있는데, 이 탐색 과정을 최대한 효율적으로 만들자 - 현재 문자열 + 1 길이만 보거나 하는 등