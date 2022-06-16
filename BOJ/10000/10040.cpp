// 투표
// https://www.acmicpc.net/problem/10040

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> cost(n), vote(n);
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	int maxx = 0, maxp = 0;
	for (int t = 0; t < m; t++) {
		int p;
		cin >> p;
		for (int i = 0; i < n; i++) {
			if (cost[i] <= p) {
				vote[i]++;
				if (maxx < vote[i]) {
					maxx = vote[i];
					maxp = i;
				}
				break;
			}
		}
	}
	cout << (maxp + 1) << '\n';
}

// n개의 경기의 개최 비용이 재미있는 순으로 주어지고, 각 유권자는 생각하는 비용을 넘기지 않는 선에서 가장 재미있는 경기를 뽑는다고 할 때, 최종 결정되는 경기는?

// 결정되는 경기는 단 하나임이 보장됨
// 각 유권자의 예상 비용을 받은 뒤, 경기 순서대로 순회하며 예상 비용 내에 있는 후보라면 바로 투표한다
// 그렇게 가장 많은 표를 받은 경기가 이기는 거지