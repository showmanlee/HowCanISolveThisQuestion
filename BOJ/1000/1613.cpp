// 역사
// https://www.acmicpc.net/problem/1613

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> history(n + 1, vector<int>(n + 1));
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		history[a][b] = -1;
		history[b][a] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (history[i][j] == 0) {
					if (history[i][k] == history[k][j] && history[i][k] != 0)
						history[i][j] = history[i][k];
				}
			}
		}
	}
	int s;
	cin >> s;
	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;
		cout << history[a][b] << '\n';
	}
}

// 각 사건들의 전후관계가 주어졌을 때, 주어진 사건의 전후관계를 판별할 수 있는가? 있다면 어떤가?

// 플로이드를 최단거리용으로 사용한다면 dist[i][k] + dist[k][j] < dist[i][j] ? dist[i][j] = dist[i][k] + dist[k][j];
// 이 원리를 이용해 플로이드를 전후관계 판별용으로 활용할 수 있다
// 입력을 받을 때 a가 b보다 먼저 일어났다고 하면, history[a][b] = -1, history[b][a] = 1로 저장한다
// 여기서 -1은 첫 번째 인덱스가 두 번째 인덱스보다 먼저 일어났다는 것이고, 1는 늦게 일어났다는 것
// 이후 최단거리 플로이드처럼 3차원 for를 돌리며 history[i][k]와 history[k][j]의 전후관계가 모두 결정되어 있고, 그 둘이 서로 같으면 history[i][j]도 결정된다 - history[i][k] or history[k][j](둘이 같음)
// 이를 말로 풀면, i가 k보다 먼저 일어나고, k가 j보다 먼저 일어났으면 i가 j보다 먼저 일어났다는 것이므로 이를 기록하는 것
// 만약 둘이 다르거나 둘 중 하나가 0이라면 알 수 없는 것이니 그대로(0) 둔다
// 이런 방식으로 플로이드를 돌려준 뒤, 주어진 쿼리에 맞게 플로이드 배열의 값을 출력해주면 됨

// 플로이드를 돌려줄 때 k->i->j 순서로 돌려줘야 함에 주의