// 가운데를 말해요
// https://www.acmicpc.net/problem/1655

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n;
	priority_queue<int> maxh;
	priority_queue<int, vector<int>, greater<int>> minh;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (maxh.size() > minh.size())
			minh.push(k);
		else
			maxh.push(k);
		if (maxh.size() != 0 && minh.size() != 0) {
			if (maxh.top() > minh.top()) {
				int a = maxh.top();
				int b = minh.top();
				maxh.pop();
				minh.pop();
				maxh.push(b);
				minh.push(a);
			}
		}
		cout << maxh.top() << '\n';
	}
}

// 수가 계속 들어올 때마다 그 중간값을 출력하라
// 근데 시간 제한이 0.1초 - 힙을 사용해야 하는 문제라는 뜻
// 중간값을 힙으로 처리하기 위해 최소 힙과 최대 힙을 동시에 굴려야 한다
// 아이디어 - 중간값이 2개일 경우 작은 값을 외쳐야 하므로 최소 힙에는 항상 최대 힙에 들어간 수보다 더 큰 수가 들어가도록 한다
//            또한 '중간값'이기 때문에 두 힙의 크기차는 1 이하를 유지해야 하며, 편의를 위해 최대 힙에 우선적으로 삽입한다(= 최소 힙의 크기가 작은 경우에만 최소 힙에 삽입)
//            언제나 최대 힙에서 중간값을 뽑기 위해, 최대 힙이 최소 힙보다 더 큰 값을 가지고 있다면 두 값을 swap한다
// priority_queue의 디폴트는 최대 힙, greater<int>로 만든 건 최소 힙임에 주의