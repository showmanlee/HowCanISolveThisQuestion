// 스택 2
// https://www.acmicpc.net/problem/28278

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> stack(1000001);
	int idx = -1;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		if (c == 1) {
			int p;
			cin >> p;
			idx++;
			stack[idx] = p;
		} else if (c == 2) {
			cout << (idx == -1 ? -1 : stack[idx]) << '\n';
			if (idx != -1) {
				idx--;
			}
		} else if (c == 3) {
			cout << (idx + 1) << '\n';
		} else if (c == 4) {
			cout << (idx == -1) << '\n';
		} else if (c == 5) {
			cout << (idx == -1 ? -1 : stack[idx]) << '\n';
		}
	}
}

// 주어진 명령을 수행하는 스택 구현하기