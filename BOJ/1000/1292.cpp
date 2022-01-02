// 쉽게 푸는 문제
// https://www.acmicpc.net/problem/1292

#include <iostream>
using namespace std;

int main(void) {
	int a[1000];
	int ctr = 0;
	for (int i = 1; ; i++) {
		for (int j = 0; j < i; j++) {
			a[ctr] = i;
			ctr++;
			if (ctr >= 1000)
				break;
		}
		if (ctr >= 1000)
			break;
	}
	int n, m;
	cin >> n >> m;
	int res = 0;
	for (int i = n - 1; i < m; i++)
		res += a[i];
	cout << res << '\n';
}

// 1 2 2 3 3 3 4 4 4 4... 꼴의 수열에서 특정 범위의 합 구하기
// 1000까지니까 미리 만들어도 됨