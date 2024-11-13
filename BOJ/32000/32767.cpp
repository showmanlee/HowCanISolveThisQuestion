// 문자열 줄이기
// https://www.acmicpc.net/problem/32627

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<char, int> pr;

bool compare(pr a, pr b) {
	if (a.first == b.first) {
		return a.second < b.second;
    }
	return a.first < b.first;
}


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<pr> v;
    vector<bool> active(n, true);
    for (int i = 0; i < n; i++) {
        v.push_back({s[i], i});
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < m; i++) {
        active[v[i].second] = false;
    }
    string res;
    for (int i = 0; i < n; i++) {
        if (active[i]) {
            res += s[i];
        }
    }
    cout << res << '\n';
}

// 주어진 소문자 문자열에서 사전상 가장 앞의 문자 중 가장 먼저 나오는 문자를 지우는 걸 반복할 때, 지운 결과 출력하기