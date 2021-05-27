// 컵라면
// https://www.acmicpc.net/problem/1781

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pr> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		if (pq.size() < v[i].first)
			pq.push(-v[i].second);
		else {
			if (-pq.top() < v[i].second) {
				pq.pop();
				pq.push(-v[i].second);
			}
		}
	}
	int res = 0;
	while (!pq.empty()) {
		res -= pq.top();
		pq.pop();
	}
	cout << res << '\n';
}

// 어떤 문제를 데드라인 안에 풀면 컵라면을 받을 수 있을 때, 주어진 문제를 풀어 최대로 컵라면을 받을 수 있는 수는?

// 문제를 푸는데는 1초가 걸린다 - 데드라인별로 묶어서 관리해줄 수 있음
// 같은 데드라인 안에서 최대한 많은 컵라면을 주는 문제(들)를 풀어야 이득 - 이를 위해 먼저 문제 배열을 데드라인을 기준으로 오름차순 정렬
// 문제 선택을 위해서는 최소 힙 활용하기 - 만약 현재 데드라인보다 적은 수의 문제를 풀었다면 해당 문제를 푼 컵라면을 힙에 삽입
// 만약 현재 데드라인 이상의 문제를 푼 상태라면(같은 데드라인이 겹친다면), 현재 데드라인에 해당되는 문제가 현재 문제보다 주는 컵라면 양이 적을 경우 많은 걸로 대체
// 이 과정을 반복하면 힙 안에는 풀 문제들만 남게 됨