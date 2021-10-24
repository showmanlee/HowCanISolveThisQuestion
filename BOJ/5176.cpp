// 대회 자리
// https://www.acmicpc.net/problem/5176

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
		int p, m;
		cin >> p >> m;
		vector<bool> seated(m + 1);
		int res = p;
		for (int i = 0; i < p; i++) {
			int k;
			cin >> k;
			if (!seated[k]) {
				res--;
			}
			seated[k] = true;
		}
		cout << res << '\n';
	}
}

// 자리의 개수와 사람들이 원하는 자리 목록이 주어졌을 떄, 원하는 자리에 앉지 못하는 사람의 수는?

// 자리를 1차원 bool 배열로 만들고, 각자 들어온 순서대로 원하는 자리가 비어있으면 해당 자리를 채운다
// 그러면서 총 인원수에서 자리에 앉은 인원을 빼준 값이 답