// 원, 탁!
// https://www.acmicpc.net/problem/28136

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
	for (int i = 0; i < n; i++) {
		if (v[i] >= v[(i + 1) % n]) {
			res++;
		}
	}
	cout << res << '\n';
}

// 원형으로 나열된 수열의 연결부를 잘라서 만들 수 있는 오름차순 수열의 개수 구하기