// 최소 힙
// https://www.acmicpc.net/problem/1927

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
				cout << -pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(-p);
	}
}

// priority_queue는 *최대 힙* - 최소 힙으로 만들려면 음수로 만들어서 넣거나 priority_queue<int, vector<int>, greater<int>> 방식으로 선언해야 함
// 참고로 greater<int>의 반대는 less<int>