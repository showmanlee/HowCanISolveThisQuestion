// 학생 인기도 측정
// https://www.acmicpc.net/problem/25325

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, string> prs;

bool compare(prs& a, prs& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    map<string, int> cnt;
    vector<prs> v;
    for (int i = 0; i < n; i++) {
        string st;
        cin >> st;
        v.push_back({0, st});
    }
    string s;
    while (cin >> s) {
        cnt[s]++;
    }
    for (auto& p : v) {
        p.first = cnt[p.second];
    }
    sort(v.begin(), v.end(), compare);
    for (auto& p : v) {
        cout << p.second << ' ' << p.first << '\n';
    }
}

// n명의 학생 목록과 인기투표 현황이 주어질 때, 투표 결과를 정렬해서 출력하기

// map으로 세고, vector로 정렬하기