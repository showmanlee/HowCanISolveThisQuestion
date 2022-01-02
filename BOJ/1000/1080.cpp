// 행렬
// https://www.acmicpc.net/problem/1080

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<bool>> a(n, vector<bool>(m)), b(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			a[i][j] = c == '1';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			b[i][j] = c == '1';
		}
	}
	int res = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				res++;
				for (int x = 0; x < 3; x++)
					for (int y = 0; y < 3; y++)
						a[i + x][j + y] = !a[i + x][j + y];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j])
				res = -1;
		}
	}
	cout << res << '\n';
}

// 어떤 2차원 비트 행렬을 다른 행렬의 형태로 만들기 위해 3*3 부분 행렬을 뒤집을 때, 바꿀 수 있는가? 있다면 최소 얼마나 뒤집어야 하는가?

// 그리디적 관점에서 이 상황을 볼 수 있음
// 우선 한 번 뒤집은 후 다시 뒤집을 필요는 없음 - 바꾸기 위해서 뒤집었는데 다시 원상태로 돌릴 필요가 없음
// 0번 비트를 뒤집으면 1번 비트와 2번 비트도 같이 뒤집혀지고, 이 상황에서 1번 비트와 2번 비트를 원상태로 돌리려면 1번 비트에 커서를 맞추고 뒤집으면 됨
// 이러한 방식으로 각 비트에 커서를 맞추면 개별 단위로 비트를 뒤집어볼 수도 있음 - 그러나 3*3 커서는 배열 밖으로 벗어날 수 없음
// 따라서 커서 범위 안에서 저 원리가 적용된다면 순차적 시도 - 그리디로 이 문제를 해결할 수 있고, 그렇지 않으면 불가능함 - 브포와는 느낌이 다름
// 이를 위해 가능한 모든 커서에 뒤집기를 시도 - 만약 커서의 첫 비트가 다르다면 뒤집고 횟수 증가
// 이후 변환된 행렬을 검사하며 다른 부분이 발견될 경우 -1, 그렇지 않으면 횟수 출력
