// Arkain 대시보드
// https://www.acmicpc.net/problem/33691

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	stack<string> st;
	map<string, bool> visit;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		st.push(s);
		visit[s] = true;
	}
	int m;
	cin >> m;
	map<string, bool> sel;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		sel[s] = true;
	}
	vector<string> prior, other;
	while (!st.empty()) {
		string s = st.top();
		st.pop();
		if (!visit[s]) {
			continue;
		}
		if (sel[s]) {
			prior.push_back(s);
		} else {
			other.push_back(s);
		}
		visit[s] = false;
	}
	for (string s : prior) {
		cout << s << '\n';
	}
	for (string s : other) {
		cout << s << '\n';
	}
}

// 주어진 순서의 문자열과 우선순위로 정렬할 문자열이 주어질 때, 최근에 나온 순서대로 문자열 정렬하기