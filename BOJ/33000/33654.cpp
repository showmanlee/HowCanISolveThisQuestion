// Sort of Sort
// https://www.acmicpc.net/problem/33654

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int prev = -987654321;
	vector<int> res;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p >= prev) {
			res.push_back(p);
			prev = p;
		}
	}
	for (int i : res) {
		cout << i << ' ';
	}
	cout << '\n';
}

// 주어진 정수 배열에서 순서를 그대로 유지하면서 오름차순이 되도록 원소 빼서 출력하기