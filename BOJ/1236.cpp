// 성 지키기
// https://www.acmicpc.net/problem/1236

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<bool> row(n), col(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == 'X') {
				row[i] = true;
				col[j] = true;
			}
		}
	}
	int r1 = 0, r2 = 0;
	for (int i = 0; i < n; i++)
		if (!row[i])
			r1++;
	for (int i = 0; i < m; i++)
		if (!col[i])
			r2++;
	int res = max(r1, r2);
	cout << res << '\n';
}

// n*m 공간의 각 행/열에 경비원을 한 명씩 놓고 싶을 때, 주어진 상태에서 추가로 필요한 경비원의 수는?

// 보드를 받으며 각 행과 열에 경비원 등장 여부를 체크
// 이후 각 행과 열의 등장 여부를 순회하며 등장하지 않은 칸들을 행/열대로 센 후, 두 수를 비교해 큰 값 출력하기
// ex. 완전히 빈 공간의 경우 긴 변의 길이만큼의 경비원이 필요함