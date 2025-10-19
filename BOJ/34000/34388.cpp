// 3-Puzzle
// https://www.acmicpc.net/problem/34388

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

	string a, b;
	cin >> a >> b;
	a += b;
	map<string, bool> visit;
	queue<pr> q;
	q.push({a, 0});
	while (!q.empty()) {
		string s = q.front().first;
		int p = q.front().second;
		q.pop();
		if (s == "123-") {
			cout << p << '\n';
			break;
		}
		int idx = 0;
		for (int i = 0; i < 4; i++) {
			if (s[i] == '-') {
				idx = i;
				break;
			}
		}
		int idxa = (idx % 2 == 0 ? idx + 1 : idx - 1);
		int idxb = (idx / 2 == 0 ? idx + 2 : idx - 2);
		string sa = s, sb = s;
		swap(sa[idx], sa[idxa]);
		swap(sb[idx], sb[idxb]);
		if (!visit[sa]) {
			visit[sa] = true;
			q.push({sa, p + 1});
		}
		if (!visit[sb]) {
			visit[sb] = true;
			q.push({sb, p + 1});
		}
	}
}

// 주어진 2*2 슬라이드 퍼즐을 맞추는 데 필요한 최소 이동 횟수 구하기