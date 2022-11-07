// 유니크
// https://www.acmicpc.net/problem/5533

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> counter(3, vector<int>(101)), board(3, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> board[j][i];
			counter[j][board[j][i]]++;
		}
	}
	for (int i = 0; i < n; i++) {
		int res = 0;
		for (int j = 0; j < 3; j++) {
			res += (counter[j][board[j][i]] == 1 ? board[j][i] : 0);
		}
		cout << res << '\n';
	}
}

// 1부터 100까지 수를 내서 그 수를 낸 사람이 유일할 경우 그만큼의 점수를 받는 게임을 3라운드 진행할 때, 최종 점수 출력하기

// 낸 숫자들을 받으면서 각 라운드에 숫자가 등장한 횟수도 세준다
// 이후 사람들이 낸 숫자들을 돌면서 한 번만 나왔었다면 점수에 더해 결과를 출력한다