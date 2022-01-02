// 텀 프로젝트
// https://www.acmicpc.net/problem/9466

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
int choose[100001];
bool visit[100001];
bool done[100001];
int res;

void dfs(int p) {
	if (visit[p])
		return;
	visit[p] = true;
	if (!visit[choose[p]])
		dfs(choose[p]);
	else if (!done[choose[p]]) {
		int cur = choose[p];
		while (cur != p) {
			res--;
			cur = choose[cur];
		}
		res--;
	}
	done[p] = true;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		memset(choose, 0, sizeof(choose));
		memset(visit, false, sizeof(visit));
		memset(done, false, sizeof(done));
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> choose[i];
		res = n;
		for (int i = 1; i <= n; i++)
			if (!visit[i])
				dfs(i);
		cout << res << '\n';
	}
}

// 학생들이 팀원으로 선택한 사람을 이어 사이클이 되면 팀이 된다고 할 때, 팀이 되지 못한 사람들은?
// dfs를 이용한 사이클 검출 - 여기엔 visit뿐만 아니라 done이라는 새로운 bool 배열이 필요하다
// visit는 dfs로 들어갈 때 체크하지만, done은 dfs를 나올 때 체크한다
// 즉, 한 dfs 안에서 visit가 false인 노드는 아직 들어가지 않는 노드란 뜻이고, done이 false인 노드는 들어갔지만 아직 처리되지 않은 노드라는 것
// 그러니까, 현재 dfs 경로(사이클) 내에 해당 노드가 존재한다는 것을 의미하고, 이는 곧 사이클이 검출되었다는 것을 의미한다
// 따라서 선택한 팀원을 따라 dfs를 돌리다가 사이클을 발견하면 반복문을 통해 사이클에 참여하는 팀원들의 수를 세서 그만큼 결과값에서 빼주는 방법으로 해결 가능
// 발견한 시점에서 사이클임이 보장되므로 반복문을 돌릴 수 있음

// 테케 전환으로 인해 전역 배열 초기화가 필요할 때 반복문 대신 memset을 이용하면 더 편리하게 초기화가 가능하다 - #include <cstring>