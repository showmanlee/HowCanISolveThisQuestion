// 슈퍼 마리오
// https://www.acmicpc.net/problem/2851

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(10), sum(10);
	int maxR = 987654321, minR = 0;
	for (int i = 0; i < 10; i++) {
		cin >> v[i];
		sum[i] = (i == 0 ? v[i] : v[i] + sum[i - 1]);
		if (sum[i] >= 100) {
			maxR = min(maxR, sum[i]);
		} else if (sum[i] <= 100) {
			minR = max(minR, sum[i]);
		}
	}
	cout << (maxR - 100 <= 100 - minR ? maxR : minR) << '\n';
}

// 일렬로 놓인 10개의 점수가 적힌 버섯을 처음부터 순차적으로 먹을 때, 100점에 가깝게 먹는 경우는?

// 첫 번째 버섯부터 각 버섯까지에 대한 누적 합을 구한 후, 합이 100 이상인 경우의 최소, 100 이하인 경우의 최대를 구한다
// 여기서 두 경우의 100과의 차를 구한 후, 더 가까운 쪽으로 출력한다