// 동방 프로젝트 (Small)
// https://www.acmicpc.net/problem/14594

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n;
int group[101];
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
	for (int i = 1; i <= n; i++) 
		group[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		for (int i = a; i < b; i++)
			unioning(i, i + 1);
	}
	set<int> res;
	for (int i = 1; i <= n; i++)
		res.insert(finding(i));
	cout << res.size() << '\n';
}

// 1번부터 n번까지의 동방이 벽으로 나누어진 상태에서 임의의 두 방 사이의 벽을 모두 뚫는 행동을 m번 할 때, 남은 동방의 수는?

// Large 문제와 같으나, n이 100까지 주어짐
// 따라서 여기서는 처음 구상했던 방법이 가능함 - a부터 b까지 양옆의 방에 union을 적용한 뒤, set을 이용해 group 안의 수를 세서 출력하기
// 물론 Large보다 비효율적인 방법임