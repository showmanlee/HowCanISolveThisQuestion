// 그래서 님 푼 문제 수가?
// https://www.acmicpc.net/problem/29720

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	int res = n - (m * k);
	int ress = max(0, res + m - 1);
	res = max(res, 0);
	cout << res << ' ' << ress << '\n';
}

// n문제를 하루에 m문제씩 k일 풀어야 모두 푼다고 할 때, 지금까지 푼 문제 범위 출력하기

// n - (m * k) ~ n - (m * (k + 1) - 1)