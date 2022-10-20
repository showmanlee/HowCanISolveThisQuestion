// 세준세비
// https://www.acmicpc.net/problem/1524

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	
	for (int t = 0; t < tt; t++) {
		int n, m;
		cin >> n >> m;
		int s = 0, b = 0;
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			s = max(s, p);
		}
		for (int i = 0; i < m; i++) {
			int p;
			cin >> p;
			b = max(b, p);
		}
		if (s < b) {
			cout << "B\n";
		} else {
			cout << "S\n";
		}
	}
}

// 세준(S)와 세비(B)가 힘이 다른 병사들로 전투하다 가장 약한 병사가 죽는 게임을 할 때, 마지막까지 병사가 남아있는 팀은?

// 게임 특성상 비기는 경우는 존재할 수 없음 - 동점일 경우 B가 지는 것이 보장되어 있기 떄문에
// 그리고 게임 진행 특성 상 결국 가장 강한 병사가 있는 쪽이 이기게 되어 있음 - 인원수에 관계없이
// 따라서 각 팀의 병사 로스터 중 가장 센 놈만 잡아 B가 더 높으면 B, 아니면 S