// 동방 프로젝트 (Large)
// https://www.acmicpc.net/problem/14595

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int group[1000001];
int wall[1000001];

int finding(int p) {
	if (p == group[p])
		return p;
	return group[p] = finding(group[p]);
}

void unioning(int a, int b) {
	int ga = finding(a);
	int gb = finding(b);
	group[ga] = gb;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	int m;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		group[i] = i;
		wall[i] = i + 1;
	}
	wall[n] = -1;
	int res = n;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		while (finding(a) != finding(b)) {
			res--;
			wall[a] = wall[finding(a)];
			unioning(a, b);
			a = wall[a];
		}
	}
	cout << res << '\n';
}

// 1번부터 n번까지의 동방이 벽으로 나누어진 상태에서 임의의 두 방 사이의 벽을 모두 뚫는 행동을 m번 할 때, 남은 동방의 수는?

// 당연하게도 union-find을 써야 하는 disjoint-set 문제
// 그러나 a, b가 들어올 때 그 사이의 모든 벽을 union으로 합친 후, group에 남은 수를 세는 방법은 시간 초과
// 따라서 a와 b 사이의 벽을 부술 때 그 사이 탐색 횟수를 줄여야 함 - 현재 칸에서 보이는 다음 벽의 위치를 기록하는 배열을 활용해볼까
// 처음에는 wall[i] = i + 1(wall[n] = -1)로 초기화된 벽의 위치 배열
// 여기서 a < b임이 보장되므로, b 그대로 놓고 a를 점점 움직이면서 벽을 깨가자
// 만약 finding(a) == finding(b)라면 두 방은 이미 이어져있다는 의미 - 그러지 않을 때까지 a를 갱신하며 벽을 깨간다
// 그러니까 어떻게? - a와 b를 union한 후, a를 wall[a]로 갱신한다
// 여기서 wall[a]는 a를 갱신하기 전 a 방의 가장 끝(finding(a))에 있는 벽 위치로 갱신한다
// 이를 위해 union 함수는 평소와 달리 더 큰 쪽을 향하도록 갱신시켜야 함