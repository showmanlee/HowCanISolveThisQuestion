// 크리스마스 선물
// https://www.acmicpc.net/problem/14235

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p == 0) {
			if (!pq.empty()) {
				int t = pq.top();
				pq.pop();
				cout << t << '\n';
			} else {
				cout << "-1\n";
			}
		} else {
			for (int j = 0; j < p; j++) {
				int t;
				cin >> t;
				pq.push(t);
			}
		}
	}
}

// 거점지를 만날 때마다 그곳에 놓인 가치가 다른 선물들을 챙기고, 아이들을 만날 때마다 가장 가치가 높은 선물들을 줄 때, 아이들이 받은 선물 현황 출력하기

// priority_queue 사용하기
// 거점지에 가면 놓인 선물들 모두 pq에 넣고, 아이들을 만나면 pop해서 준다
// 만약 pq가 비어 있으면 -1 출력하기