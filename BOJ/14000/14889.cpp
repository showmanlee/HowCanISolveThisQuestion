// 스타트와 링크
// https://www.acmicpc.net/problem/14889

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int res;
int board[21][21];
int check[11];

void select(int count) {
	if (count == n / 2) {
		vector<bool> team(n + 1);
		for (int i = 0; i < n / 2; i++)
			team[check[i]] = true;
		vector<int> a, b;
		for (int i = 1; i <= n; i++) {
			if (team[i])
				a.push_back(i);
			else
				b.push_back(i);
		}
		int p = 0, q = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = i; j < n / 2; j++) {
				p += board[a[i]][a[j]];
				p += board[a[j]][a[i]];
				q += board[b[i]][b[j]];
				q += board[b[j]][b[i]];
			}
		}
		res = min(res, abs(p - q));
		return;
	}
	int beg = (count == 0 ? 1 : check[count - 1] + 1);
	for (int i = beg; i <= n; i++) {
		check[count] = i;
		select(count + 1);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	res = 987654321;
	select(0);
	cout << res << '\n';
}

// 두 사람이 같은 팀이 되었을 때 추가되는 능력치 목록이 주어질 때, n명을 두 팀으로 나눌 때 생기는 두 팀간의 능력치 차의 최소는?
// 브루트포스 - n명 중 n/2명을 뽑고, 뽑힌 팀과 뽑히지 않은 팀으로 나눠 능력치를 구해 그 차를 구한다
// 이렇게 구한 능력치를 이용해 결과값을 갱신시킨 후 최종 결과 출력