// 기상캐스터
// https://www.acmicpc.net/problem/10709

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, 987654321));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == 'c') {
				for (int k = j; k < m; k++) {
					v[i][k] = k - j;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 987654321) {
				v[i][j] = -1;
			}
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
}

// n*m 보드에서 현재 구름 상태가 주어지고, 1분에 동쪽으로 한 칸씩 이동한다고 할 떄, 각 칸에 구름이 몇 분 뒤에 도착하는지 판정하기

// 일단 구름이 있는 칸은 0으로 채우기, 그리고 그 칸으로부터 오른쪽 칸들에 순서대로 숫자 넣게
// 입력을 좌측부터 받기 떄문에, 구름이 새로 나온다면 새로 덮어써주면 됨 - 우측에 있는 구름일 수록 먼저 도착할 테니까