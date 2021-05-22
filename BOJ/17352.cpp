// 여러분의 다리가 되어 드리겠습니다!
// https://www.acmicpc.net/problem/17352

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int group[300001];

int finding(int p) {
	if (p == group[p])
		return p;
	return group[p] = finding(group[p]);
}

void unioning(int a, int b) {
	int ga = finding(a), gb = finding(b);
	if (ga < gb)
		group[gb] = ga;
	else
		group[ga] = gb;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		group[i] = i;
	for (int i = 0; i < n - 2; i++) {
		int a, b;
		cin >> a >> b;
		unioning(a, b);
	}
	for (int i = 1; i <= n; i++)
		finding(i);
	int s = group[1], t;
	for (int i = 2; i <= n; i++) {
		if (group[i] != s) {
			t = i;
			break;
		}
	}
	cout << 1 << ' ' << t << '\n';
}

// n - 1개의 다리로 모두 이어져 있던 n개의 섬에서 다리 하나가 끊어졌을 때, 모든 섬을 이을 수 있도록 다리를 놓을 수 있는 방법(중 하나)은?

// n - 1개의 다리로 이어진 n개의 섬 - 트리 형태로 이어져 있었음 - 여기서 다리 하나가 끊어지면 두 덩어리가 됨이 보장됨
// union-find로 2개의 덩어리로 나눈 후, 1번 섬과 1번과 다른 그룹에 있는 섬을 이어주면 됨
// 여기서 그룹 번호를 갱신하기 위해 find 함수를 섬 전체에 대해 한 번 돌려줘야 함에 주의