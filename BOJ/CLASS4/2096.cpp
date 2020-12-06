// 내려가기
// https://www.acmicpc.net/problem/2096

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int dpt[3] = { 0, 0, 0 };
	int dpb[3] = { 0, 0, 0 };
	int cur[3] = { 0, 0, 0 };
	int n;
	cin >> n;
	cin >> cur[0] >> cur[1] >> cur[2];
	dpt[0] = dpb[0] = cur[0];
	dpt[1] = dpb[1] = cur[1];
	dpt[2] = dpb[2] = cur[2];
	for (int i = 1; i < n; i++) {
		cin >> cur[0] >> cur[1] >> cur[2];
		int zero = dpt[0], two = dpt[2];
		dpt[0] = max(dpt[0], dpt[1]) + cur[0];
		dpt[2] = max(dpt[1], dpt[2]) + cur[2];
		dpt[1] = max(zero, max(dpt[1], two)) + cur[1];
		zero = dpb[0]; two = dpb[2];
		dpb[0] = min(dpb[0], dpb[1]) + cur[0];
		dpb[2] = min(dpb[1], dpb[2]) + cur[2];
		dpb[1] = min(zero, min(dpb[1], two)) + cur[1];
	}
	cout << (max(dpt[0], max(dpt[1], dpt[2]))) << ' ' << (min(dpb[0], min(dpb[1], dpb[2]))) << '\n';
}

// 3열로 구성된 게임 보드를 아래 또는 한 칸 대각선 방향으로 내려가면서 점수를 먹을 때 최대/최소로 먹을 수 있는 점수는?
// DP 문제 - 메모리 제한이 빡빡하기 때문에 전체를 저장할 수는 없음
// 해당 칸의 값들을 받고, dp에는 갈 수 있는 칸들 중 최대/최소인 값을 저장
// ! 처음엔 그 칸의 값을 넣어줘야 함, min/max 비교를 cur가 아닌 dp에서 해줘야 함(어디서 왔는지 알아야 하니까 - 따라서 0, 2 값은 별도 저장 필요)
// 최대에서 최소까지 구해야 하기에 dp를 2개 돌려야 함