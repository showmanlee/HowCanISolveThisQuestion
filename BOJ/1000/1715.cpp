// 카드 정렬하기
// https://www.acmicpc.net/problem/1715

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	int sum = 0;
	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		sum += a + b;
		pq.push(a + b);
	}
	cout << sum << '\n';
}

// 카드 X장 더미와 Y장 더미를 합치려면 X+Y번 비교해야 한다
// 이게 왜 우선순위 큐? - 작은 순으로 계속 정렬해야 하거든(최소 힙)
// 가장 작은 두 묶음을 더해서 힙에 다시 넣어주고, 또 가장 작은 두 묶음을 더해서 힙에 넣어준다
// 10 20 40 -> (10+20) 40 -> 30 40 -> (30+40) -> 70
// 그리고 그 더한 값을 결과에 더해준다
// n == 1일 경우 비교 자체가 불필요하므로 break