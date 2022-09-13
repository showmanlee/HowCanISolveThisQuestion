// 핸들 뭘로 하지
// https://www.acmicpc.net/problem/25498

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string str;
	cin >> str;
	str = " " + str;
	vector<vector<int>> board(n + 1);
	vector<int> visit(n + 1, -1);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}
	string res;
	queue<int> q;
	q.push(1);
	visit[1] = 1;
	res += str[1];
	while (!q.empty()) {
		vector<int> candi;
		char c = ' ';
		int ss = q.size();
		for (int t = 0; t < ss; t++) {
			int p = q.front();
			q.pop();
			for (int i : board[p]) {
				if (visit[i] == -1) {
					visit[i] = visit[p] + 1;
					q.push(i);
					c = max(c, str[i]);
				}
			}
		}
		if (c != ' ') {
			res += c;
		}
		queue<int> t;
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			if (str[p] == c) {
				t.push(p);
			}
		}
		q = t;
	}
	cout << res << '\n';
}

// 문자들로 구성된 트리가 주어졌을 때, 해당 트리에서 뽑을 수 있는 사전 상 마지막 문자열 출력하기

// 문자 개수가 50만 개라서 bfs로 모든 문자 경우를 뽑아낸다 하더라도 시간과 메모리에서 막혀버릴 수 있음
// 사전 순 마지막 문자열은 각 단계에서 나올 수 있는 가장 마지막 문자들을 이어붙이면 만들 수 있음 - 문제는 이것들이 모두 이어져야 함
// 따라서 1번 노드부터 bfs로 트리를 순회하면서, 각 단계마다 등장하는 가장 마지막 문자를 찾아 그 문자가 나오는 노드만 다음 단계 큐에 넣는다
// 그리고 그렇게 얻어지는 마지막 문자들을 순서대로 이어붙여 답을 출력한다