// 과제는 끝나지 않아!
// https://www.acmicpc.net/problem/17952

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class node {
	public:
	int point = 0;
	int time = 0;
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	stack<node*> st;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p == 1) {
			node* d = new node;
			cin >> d->point >> d->time;
			st.push(d);
		}
		if (!st.empty()) {
			st.top()->time--;
			if (st.top()->time == 0) {
				res += st.top()->point;
				node* d = st.top();
				st.pop();
				delete d;
			}
		}
	}
	cout << res << '\n';
	while (!st.empty()) {
		node* d = st.top();
		st.pop();
		delete d;
	}
}

// 실행하는데 t분이 걸리는 a점짜리 과제를 실시간으로 쌓이는 순서대로 수행할 때, n분동안 해서 얻을 수 있는 점수 출력하기