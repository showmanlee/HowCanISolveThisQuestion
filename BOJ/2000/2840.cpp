// 행운의 바퀴
// https://www.acmicpc.net/problem/2840

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<char> v(n, '?');
	int idx = 0;
	bool fail = false;
	for (int i = 0; i < m; i++) {
		int p;
		char c;
		cin >> p >> c;
		idx -= p;
		while (idx < 0) {
			idx += n;
		}
		if (v[idx] != '?' && v[idx] != c) {
			fail = true;
		} else {
			v[idx] = c;
		}
	}
	for (int i = 0; i < n; i++) {
		if (v[i] == '?') {
			continue;
		}
		for (int j = i + 1; j < n; j++) {
			if (v[i] == v[j]) {
				fail = true;
			}
		}
	}
	if (fail) {
		cout << "!\n";
	} else {
		for (int i = 0; i < n; i++) {
			cout << v[(idx + i) % n];
		}
		cout << '\n';
	}
}

// 시계방향으로 돌아가는 원판의 각 칸에 알파벳이 적혀 있고, p칸 이동 후 c칸이 적혀있다는 정보들이 주어졌을 떄, 원판에 적힌 글자들 순서대로 출력하기

// 인덱스에서 p칸 뒤로 이동 후 그 칸에 글자를 적는다
// 여기서 해당 칸에 글자가 이미 적혀 있는 경우 불가능한 경우이므로 ! 출력
// 아니라면 계속 글자를 적고, 마지막 인덱스에서 정방향으로 글자 출력하기
// 원판 안의 글자들은 중복되지 않음에도 주의