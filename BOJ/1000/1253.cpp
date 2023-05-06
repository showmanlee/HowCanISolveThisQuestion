// 좋다
// https://www.acmicpc.net/problem/1253

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int res = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int f = 0, r = n - 1;
		while (f < r) {
			int p = v[f] + v[r];
			if (p == v[i]) {
				if (f != i && r != i) {
					res++;
					break;
				} else if (f == i) {
					f++;
				} else if (r == i) {
					r--;
				}
			} else if (p > v[i]) {
				r--;
			} else {
				f++;
			}
		}
	}
	cout << res << '\n';
}

// 배열이 주어질 때, 주어진 수를 다른 두 수의 합으로 나타낼 수 있는 경우의 수는?

// 3개의 인덱스를 선택해야 하는 문제 - n^3로 풀면 간단하지만 당연하게도 그러면 안 됨
// 왼쪽/오른쪽 인덱스를 골라주는 건 투 포인터로 최적화 가능 - 같은 위치의 수를 쓰면 안 되니까 정렬해도 큰 문제는 없음
// 그래서 정렬한 후 일반적인 투 포인터로 돌리되, 정답에 도달했을 때 같은 인덱스를 쓰고 있다면 겹친 인덱스 포인터를 움직여서 다시 보게 한다