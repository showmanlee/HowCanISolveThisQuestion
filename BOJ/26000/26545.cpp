// Mathematics
// https://www.acmicpc.net/problem/26545

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		res += p;
	}
	cout << res << '\n';
}

// 주어진 수를 모두 더하기

// 문제에 범위가 없으나 int 범위로 해결 가능