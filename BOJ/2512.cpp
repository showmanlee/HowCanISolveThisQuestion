// 예산
// https://www.acmicpc.net/problem/2512

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n;
	vector<int> board(n);
	for (int& i : board)
		cin >> i;
	cin >> m;
	int left = 0;
	int right = *max_element(board.begin(), board.end());
	int maxx = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;
		for (int i : board)
			sum += min(i, mid);
		if (sum <= m) {
			maxx = max(maxx, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	int res = 0;
	for (int i : board)
		res = max(res, min(i, maxx));
	cout << res << '\n';
}

// 지방들의 예산 요청액과 총액이 주어진 상황에서 지급 상한액을 지정할 수 있을 때, 총액 안에서 한 지방에 지급할 수 있는 최대 금액은?

// 지급 상한액을 정하는데는 이분 탐색이 필요함(지방 수 1만 개 * 지방 별 최대 요청액 10만 = ?)
// 최솟값은 0, 최댓값은 요청액의 최대로 설정하여 이분 탐색 시작
// 각 지방별 요청액과 현재 상한가 중 작은 값을 모두 더한 후, 그 값이 m 이하인 경우 결과 상한가를 갱신하며 left를 당기고, 그렇지 않으면 right를 당긴다
// 이후 결과 상한가가 정해지면 각 지방별 요청액과 결과 상한가 중 작은 값들 중 최댓값을 뽑아서 출력하기