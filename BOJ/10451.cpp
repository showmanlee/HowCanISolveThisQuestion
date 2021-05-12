// 순열 사이클
// https://www.acmicpc.net/problem/10451

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
		
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		vector<int> v(n + 1);
		vector<bool> visit(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				visit[i] = true;
				int cur = i;
				while (true) {
					cur = v[cur];
					if (!visit[cur])
						visit[cur] = true;
					else {
						res++;
						break;
					}
				}
			}
		}
		cout << res << '\n';
	}
}

// 한 원소가 다른 원소를 가리키는 순열이 있을 때, 순열에 존재하는 사이클의 수 구하기
// 일종의 단방향 그래프이므로 while을 이용한 dfs로 접근
// 1부터 n까지 순회하며 방문하지 않은 노드를 발견하면 해당 노드부터 다시 해당 노드를 방문할 때까지 가리키는 노드를 순회하고, 사이클 수를 늘려준다