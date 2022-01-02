// 미네크래프트
// https://www.acmicpc.net/problem/15708

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, t, p;
	cin >> n >> t >> p;
	vector<int> stones(n);
	for (int i = 0; i < n; i++)
		cin >> stones[i];
	int res = 0, cnt = 0, sum = 0;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		if (t <= p * i)
			break;
		pq.push(stones[i]);
		cnt++;
		sum += stones[i];
		while (!pq.empty() && sum > t) {
			sum -= pq.top();
			cnt--;
			pq.pop();
		}
		if (sum > t)
			break;
		res = max(res, cnt);
		sum += p;
	}
	cout << res << '\n';
}

// 왼쪽부터 일렬로 놓인 크기와 부수는 시간이 다른 바위 n개를 그냥 지나치는데 p초가 걸릴 때, t초 안에 부술 수 있는 바위의 최대 개수는?

// 지나갈 수 있는 바위는 최대한 지나가면서, 부술 수 있는 있는 바위는 최대한 부숴주기 - 왼쪽부터 모든 개수에 대해 계산
// 지나가는 바위 판정을 위해 최대 힙을 활용해보자 - 만약 현재까지 쌓인 시간이 t보다 커진 경우 큰 바위부터 없애기
// 모든 바위를 순회하며 처음에는 pq에 해당 바위를 넣어주고, 개수와 시간도 누적시키기
// 만약 이 상태에서 누적 시간이 t보다 커진 경우 pq에서 큰 것부터 하나씩 빼기
// 이 상태에서도 누적 시간이 t보다 큰 경우 더 이상 캐는 게 의미가 없으니 탐색 종료
// 그렇지 않다면 누적 시간에 p 누적하기 - 여기서 p를 누적시켜도 pq.pop이 while 기반으로 돌아가므로 모든 케이스를 탐색할 수 있음