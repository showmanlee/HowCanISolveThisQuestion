// 악질 검거
// https://www.acmicpc.net/problem/31823

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, string> prs;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<prs> v;
    vector<int> cnt(201);
    int shown = 0;
    for (int i = 0; i < n; i++) {
        char c;
        int p = 0, maxx = 0;
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c == '.') {
                p++;
                maxx = max(p, maxx);
            } else {
                p = 0;
            }
        }
        string s;
        cin >> s;
        v.push_back({maxx, s});
        cnt[maxx]++;
        if (cnt[maxx] == 1) {
            shown++;
        }
    }
    cout << shown << '\n';
    for (auto p : v) {
        cout << p.first << ' ' << p.second << '\n';
    }
}

// n명의 스트릭 현황과 이름이 주어질 때, 문제에 적힌 대로 결과 출력하기

// 문제를 안 푼 경우가 연속으로 주어지는 갯수를 세고, 이를 이름과 함께 저장해서 출력한다
// 등장한 스트릭 길이 종류 개수도 출력해야 함에 주의