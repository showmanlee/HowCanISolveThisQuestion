// 자료구조는 정말 최고야
// https://www.acmicpc.net/problem/23253

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<stack<int>> stacks(m);
	vector<int> idx(n + 1);
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int p;
			cin >> p;
			stacks[i].push(p);
			idx[p] = i;
		}
	}
	int res = true;
	for (int i = 1; i <= n; i++) {
		if (!stacks[idx[i]].empty() && stacks[idx[i]].top() == i) {
			stacks[idx[i]].pop();
		}
		else {
			res = false;
			break;
		}
	}
	cout << (res ? "Yes" : "No") << '\n';
}

// 1~n까지의 번호가 적힌 책들이 m개의 더미에 쌓여있을 때, 각 더미의 맨 위만 접근하여 책들을 정렬할 수 있는가?

// 스택 문제 - m개의 스택으로 흩어진 1~n을 정렬할 수 있나요?
// 스택들은 배열로 관리하고, 해당 숫자가 들어간 스택의 번호도 별도의 배열에 따로 관리
// 이렇게 스택들에 숫자들을 넣고, 1부터 숫자들을 빼보며 뺄 수 있으면 진행하고, 그렇지 않아면 실패 판정
// 물론 이것보다 더 라이트한 방법도 있음... 뭘까?