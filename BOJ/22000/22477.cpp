// Kagisys
// https://www.acmicpc.net/problem/22477

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	map<string, bool> visit;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		visit[s] = true;
	}
	int m;
	cin >> m;
	bool open = false;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (visit[s]) {
			open = !open;
			cout << (open ? "Opened" : "Closed") << " by " << s << '\n';
		} else {
			cout << "Unknown " << s << '\n';
		}
	}
}

// 등록된 ic카드만 문을 열고 닫을 수 있는 문에 대해 등록된 ic카드 목록과 태깅 현황이 주어졌을때, 개폐 로그 출력하기