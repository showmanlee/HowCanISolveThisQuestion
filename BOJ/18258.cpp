// 큐 2
// https://www.acmicpc.net/problem/18258

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void) {
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    
	queue<int> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string p;
		cin >> p;
		if (p == "push") {
			int i;
			cin >> i;
			q.push(i);
		}
		else if (p == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (p == "size")
			cout << q.size() << '\n';
		else if (p == "empty")
			cout << (q.empty() ? 1 : 0) << '\n';
		else if (p == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else 
				cout << q.front() << '\n';
		}
		else if (p == "back") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}
}

// 이번엔 입력이 2백만개나 들어와서 시간복잡도도 체크해야 하고(큐에서 넣고 빼는데 O(1)) cin 속도도 체크해야 함
// 하지만 큐가 FIFO라는 건 언제나 같음