// 아 맞다 마늘
// https://www.acmicpc.net/problem/32978

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
    map<string, bool> visit;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < n - 1; i++) {
        string s;
        cin >> s;
        visit[s] = true;
    }
    for (string s : v) {
        if (!visit[s]) {
            cout << s << '\n';
            break;
        }
    }
}

// 필요한 재료와 실제로 넣은 재료의 종류가 주어질 때, 빠진 재료 하나 구하기