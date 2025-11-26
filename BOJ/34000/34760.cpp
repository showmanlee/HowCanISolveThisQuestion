// 코끼리 15마리가 앞으로 돌진하면 어떻게 막을 건데
// https://www.acmicpc.net/problem/34760

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int res = 0, idx = 0;
	for (int i = 1; i <= 15; i++) {
		int p;
		cin >> p;
		if (res < p) {
			res = p;
			idx = i;
		}
	}
	if (idx != 15) {
		res++;
	}
	cout << res << '\n';
}

// 15마리의 코 길이가 모두 다른 코끼리들에 대해 같거나 더 큰 당근으로 막을 수 있을 때, 모든 코끼리를 막을 수 있는 당근 길이 출력하기