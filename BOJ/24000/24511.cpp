// queuestack
// https://www.acmicpc.net/problem/24511

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> types(n);
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		cin >> types[i];
	}
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (types[i] == 0) {
			dq.push_back(p);
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		dq.push_front(p);
		cout << dq.back() << ' ';
		dq.pop_back();
	}
	cout << '\n';
}

// stack와 queue가 순서대로 이어진 자료구조에서 데이터를 넣었을 때 나오는 결과 출력하기