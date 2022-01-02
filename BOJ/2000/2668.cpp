// 숫자고르기
// https://www.acmicpc.net/problem/2668

#include <iostream>
#include <vector>
using namespace std;

int n;
int choose[101];
bool visit[101];
bool done[101];
bool cycle[101];

void dfs(int p) {
	if (visit[p])
		return;
	visit[p] = true;
	if (!visit[choose[p]])
		dfs(choose[p]);
	else if (!done[choose[p]]) {
		int cur = choose[p];
		while (cur != p) {
			cycle[cur] = true;
			cur = choose[cur];
		}
		cycle[cur] = true;
	}
	done[p] = true;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> choose[i];
	for (int i = 1; i <= n; i++)
		if (!visit[i])
			dfs(i);
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (cycle[i])
			res++;
	cout << res << '\n';
	for (int i = 1; i <= n; i++)
		if (cycle[i])
			cout << i << '\n';
}

// 첫째 줄에는 1~n이 순서대로 적혀 있고, 둘째 줄에는 1~n이 무작위로 적힌 표기 있다.
// 첫째 줄에서 숫자를 적절히 뽑으면, 그 뽑힌 정수들이 이루는 집합과, 뽑힌 정수들의 바로 밑의 둘째 줄에 들어있는 정수들이 이루는 집합이 일치한다. 
// 이때, 최대한 많이 뽑을 수 있는 개수와 뽑은 정수 출력하기

// 즉, 사이클을 이루는 수들을 모두 출력하기
// dfs를 통한 사이클 검출 방법 - 노드에 들어왔음을 표시하는 visit와 노드에서 나왔음을 표시하는 done을 이용한 사이클 탐색
// 만약 다음 노드를 탐색하지 않았다면 탐색하러 들어가고,
//      다음 노드에 들어간 적은 있으나 나온 적이 없다면 사이클이므로 사이클이 되는 번호들에 사이클임을 표시한다
// 모든 탐색을 마친 후 사이클이 된 번호 수를 세고, 해당 원소들을 출력한다