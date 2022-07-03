// 대통령 선거
// https://www.acmicpc.net/problem/9547

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> board(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		if (n == 1) {
			cout << "1 1\n";
			continue;
		}
		vector<int> cnt(n + 1);
		for (int i = 0; i < m; i++) {
			cnt[board[i][0]]++;
		}
		vector<pr> sorter(n);
		for (int i = 1; i <= n; i++) {
			sorter[i - 1] = {-cnt[i], i};
		}
		sort(sorter.begin(), sorter.end());
		if (-sorter[0].first > m / 2) {
			cout << sorter[0].second << " 1\n";
			continue;
		}
		int a = sorter[0].second, b = sorter[1].second;
		int cnta = 0, cntb = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == a) {
					cnta++;
					break;
				}
				if (board[i][j] == b) {
					cntb++;
					break;
				}
			}
		}
		cout << (cnta > cntb ? a : b) << " 2\n";
	}
}

// n명의 후보와 m명의 유권자가 참여하고, 1차 투표에서 과반 득표자가 없으면 상위 2명이 2차 투표를 하는 방식의 선거에서 각 유권자의 선호도가 주어지고 그 선호도대로 투표함이 보장될 때, 당선자와 당선 시점 구하기

// 1차 투표의 경우 모두가 자신의 1순위 후보를 뽑게 된다 - 따라서 모두의 1순위로 카운팅
// 이후 카운트를 기호(1~n)와 함께 pair로 묶어 정렬한다 - 1차 투표에서는 2/3위의 득표율은 다름이 보장됨(3자 재투표는 없음)
// 이렇게 정렬한 결과 1위의 득표수가 과반수가 안 되면, 2위까지의 기호를 저장해둔다
// 이후 각 유권자의 선호도를 돌면서 두 기호 중 먼저 나온 기호에 대한 득표를 누적한다 - 그리고 둘 중 이긴 쪽으로 최종 출력하기(유권자는 홀수 = 결선투표에서 동률이 나오지 않음)
// 후보가 1명일 수도 있음에 주의 - 이 경우 1 1을 출력하고 종료