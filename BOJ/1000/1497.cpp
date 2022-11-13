// 기타콘서트
// https://www.acmicpc.net/problem/1497

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int res = 987654321;
int n, m;
int songs = 0;
long long board[11];

void dfs(int idx, int cnt, long long bit) {
	long long bitt = bit;
	int s = 0;
	for (int i = 0; i < m; i++) {
		if (bitt % 2 == 1) {
			s++;
		}
		bitt /= 2;
	}
	if (s > songs) {
		songs = s;
		res = cnt;
	} else if (s == songs) {
		res = min(res, cnt);
	}
	if (idx == n) {
		return;
	}
	dfs(idx + 1, cnt + 1, bit | board[idx]);
	dfs(idx + 1, cnt, bit);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s, t;
		cin >> s >> t;
		for (int j = 0; j < m; j++) {
			if (t[j] == 'Y') {
				board[i] |= (1ll << j);
			}
		}
	}
	dfs(0, 0, 0);
	cout <<  (res == 0 ? -1 : res) << '\n'; 
}

// 칠 수 있는 곡이 다른 기타와 곡의 개수, 그리고 기타당 칠 수 있는 곡 명단이 주어질 때, 최대한 많은 곡을 치는데 필요한 최소한의 기타 수 구하기

// 반드시 모두 칠 필요는 없음 - 최대한 많은 곡을 확보한 상황에서 최소한의 기타 수를 구하면 됨
// 탐색 자체는 dfs 기반 비트마스킹으로 처리 - 기타가 많이야 10개이므로
// 현재 리스트에서 칠 수 있는 곡 수를 보고 같으면 최소값으로만 갱신, 더 많으면 둘 다 갱신