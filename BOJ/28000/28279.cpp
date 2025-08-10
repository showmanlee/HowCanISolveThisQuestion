// 덱 2
// https://www.acmicpc.net/problem/28279

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	deque<int> q;
	for (int i = 0; i < n; i++) {
		int c, p;
		cin >> c;
		switch (c) {
			case 1:
				cin >> p;
				q.push_front(p);
				break;
			case 2:
				cin >> p;
				q.push_back(p);
				break;
			case 3:
				if (q.empty()) {
					cout << -1 << '\n';
				} else {
					cout << q.front() << '\n';
					q.pop_front();
				}
				break;
			case 4:
				if (q.empty()) {
					cout << -1 << '\n';
				} else {
					cout << q.back() << '\n';
					q.pop_back();
				}
				break;
			case 5:
				cout << q.size() << '\n';
				break;
			case 6:
				cout << q.empty() << '\n';
				break;
			case 7:
				if (q.empty()) {
					cout << -1 << '\n';
				} else {
					cout << q.front() << '\n';
				}
				break;
			case 8:
				if (q.empty()) {
					cout << -1 << '\n';
				} else {
					cout << q.back() << '\n';
				}
				break;
			default:
				break;
		}
	}
}

// 어떤 수의 자릿수를 제곱한 것을 합친 함수를 돌릴 떄, 1로 수렴하는지 구하기