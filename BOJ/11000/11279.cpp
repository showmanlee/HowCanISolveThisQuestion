// 최대 힙
// https://www.acmicpc.net/problem/11279

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	priority_queue<int> pq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(p);
	}
}

// STL에서는 최대 힙 자료구조를 제공함 - <queue> 안의 priority_queue
// 하지만 기본적인 구조는 당연히 알아야지요
// 힙은 이진 트리 형식으로 구현하여 나보다 더 작은 놈들이 내 아래로 가도록 저장
// 힙에 값을 넣을 때는 트리 맨 뒤에 넣어서 내 부모와 비교해가면서 위치 변경
// 값을 뺄 때는 맨 앞을 빼고 맨 뒤에 있던 친구를 맨 앞 자리에 넣어 내 자식 중 가장 큰(최소는 작은) 놈과 비교하며 위치 변경