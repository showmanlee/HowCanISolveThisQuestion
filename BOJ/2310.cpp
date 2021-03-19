// 어드벤처 게임
// https://www.acmicpc.net/problem/2310

#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& door, vector<int>& fee, vector<bool> visit, int start, int money, int dest) {
	if (money < 0)
		return false;
	if (start == dest)
		return true;
	int ret = false;
	for (int d : door[start]) {
		if (!visit[d]) {
			visit[d] = true;
			int nmoney = money;
			if (fee[d] > 0 && nmoney < fee[d])
				nmoney = fee[d];
			else if (fee[d] < 0)
				nmoney += fee[d];
			if (dfs(door, fee, visit, d, nmoney, dest))
				ret = true;
			visit[d] = false;
		}
	}
	return ret;
}

int main(void) {
	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		vector<int> fee(n + 1);
		vector<vector<int>> door(n + 1, vector<int>());
		for (int i = 1; i <= n; i++) {
			char c;
			int m;
			cin >> c >> m;
			if (c == 'T')
				fee[i] = -m;
			else
				fee[i] = m;
			while (true) {
				int d;
				cin >> d;
				if (d == 0)
					break;
				door[i].push_back(d);
			}
		}
		vector<bool> visit(n + 1);
		visit[1] = true;
		cout << (dfs(door, fee, visit, 1, 0, n) ? "Yes" : "No") << '\n';
	}
}

// 1번 방에서 출발해 n번 방으로 가려는데, 각 방마다 돈을 일정양만큼 채워주는 레프리콘과 통행료를 받는 트롤이 있다. 이때 돈이 떨어지지 않고 n번방에 도달할 수 있는가?
// DFS - 통행료/지급비용과 지도를 동시에 들고 가야 함
// n번 방에 도달해도 돈이 없으면 아웃임에 주의 - false를 먼저 판정한 다음 true를 판정해야 함
// 돈 지급과 지불의 메커니즘이 다름에 주의 - 지급은 얼마까지 채워주는 거(넘으면 패스)고, 지불은 말 그대로 지불