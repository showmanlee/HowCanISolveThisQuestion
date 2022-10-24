// 통나무 건너뛰기
// https://www.acmicpc.net/problem/11497

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
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int res = 0;
		for (int i = 0; i < n - 2; i++) {
			res = max(res, v[i + 2] - v[i]);
		}
		cout << res << '\n';
	}
}

// 주어진 통나무들을 원형으로 둘러세울 때, 서로 붙은 통나무 높이의 차의 최댓값이 최소가 되도록 한 결과 구하기

// 그냥 직선으로 세우는 거였다면 정렬만 하면 되지만, 여기서는 원형으로 세우는 상황 - 그냥 정렬만 하면 양 끝점 차 때문에 정답이 아님
// 이를 방지하기 위해서는 정렬한 결과를 중앙부터 좌우로 교대로 놓으면 됨 - 즉 한 칸 건너 통나무가 서로 붙는 상황
// 따라서 정렬된 배열에서 한 칸 너머 원소끼리의 차 중 최댓값을 출력한다