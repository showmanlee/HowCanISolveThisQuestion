// 성격 진단 테스트
// https://www.acmicpc.net/problem/4305

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
vector<int> board[27], board_inv[27];
stack<int> st;
bool visit[27];
bool shown[27];
vector<vector<int>> scc;
int sccidx;

void dfs(int p) {
	visit[p] = true;
	for (int i : board[p]) {
		if (!visit[i])
			dfs(i);
	}
	st.push(p);
}

void dfs_inv(int p) {
	visit[p] = true;
	scc[sccidx].push_back(p);
	for (int i : board_inv[p]) {
		if (!visit[i])
			dfs_inv(i);
	}
}

bool sorter(vector<int>& a, vector<int>& b) {
	return a[0] < b[0];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i <= 26; i++) {
			board[i].clear();
			board_inv[i].clear();
		}
		memset(visit, false, sizeof(visit));
		memset(shown, false, sizeof(shown));
		scc.clear();
		sccidx = -1;
		for (int i = 0; i < n; i++) {
			vector<char> inputs(5);
			for (int j = 0; j < 5; j++) {
				cin >> inputs[j];
				shown[inputs[j] - 'A'] = true;
			}
			char core;
			cin >> core;
			for (int j = 0; j < 5; j++) {
				if (inputs[j] != core) {
					board[core - 'A'].push_back(inputs[j] - 'A');
					board_inv[inputs[j] - 'A'].push_back(core - 'A');
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			if (shown[i] && !visit[i])
				dfs(i);
		}
		memset(visit, false, sizeof(visit));
		while (!st.empty()) {
			int i = st.top();
			st.pop();
			if (!visit[i]) {
				sccidx++;
				scc.push_back(vector<int>());
				dfs_inv(i);
			}
		}
		for (vector<int>& v : scc)
			sort(v.begin(), v.end());
		sort(scc.begin(), scc.end());
		for (vector<int>& v : scc) {
			for (int i : v)
				cout << char(i + 'A') << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
}

// 5개의 선지 중 선호도가 높은 것 하나를 선택하는 성격 진단 테스트 결과가 주어졌을 때, 선지 중 서로 다른 결과를 선택하면 모순이 발생하는 그룹 출력하기

// SCC 문제 - 같은 그룹(SCC) 안에 있는 내용은 모두 같은 걸 선택해야 모순이 발생하지 않음(2-SAT과 비슷)
// 우선 5개의 선지를 받아 각각의 선지가 모두 등장함을 표시한 후, 선택한 것을 받아 선택한 것과 선택받지 못한 것을 단방향 그래프로 잇기
// 이후 코사라주를 돌리면서 이중 vector 기반으로 SCC를 만들어준 뒤, SCC vector를 정렬 - 각 SCC를 정렬, 이후 SCC끼리 첫 글자를 보고 정렬
// 이렇게 정렬한 SCC들을 차례로 출력하기 - 각 테케가 끝나면 공백이 들어가야 함에 주의