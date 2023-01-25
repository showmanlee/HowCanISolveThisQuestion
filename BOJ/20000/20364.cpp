// 부동산 다툼
// https://www.acmicpc.net/problem/20364

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n, m;
	cin >> n >> m;
	map<long long, bool> aqq;
	for (int i = 0; i < m; i++) {
		long long pp;
		cin >> pp;
		long long p = pp;
		vector<long long> v;
		while(p != 0) {
			v.push_back(p);
			p /= 2;
		}
		reverse(v.begin(), v.end());
		bool pass = true;
		for (long long t : v) {
			if (aqq[t]) {
				cout << t << '\n';
				pass = false;
				break;
			}
		}
		if (pass) {
			cout << 0 << '\n';
			aqq[pp] = true;
		}
	}
}

// 완전 이진 트리의 칸 수와 원하는 칸들이 순서대로 주어질 떄, 1번 노드에서 해당 칸으로 도달하면서 막히게 되는 칸 출력하기(없으면 0)

// 해당 칸에서 1로 거슬러올라가는 경로를 만든 뒤, 내려가면서 방문한 칸 체크하기
// 방문한 칸 체트는 map으로 - 일반 배열로는 칸 번호가 2^20이라 불가능