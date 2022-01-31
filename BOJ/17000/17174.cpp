// 전체 계산 횟수
// https://www.acmicpc.net/problem/17174

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int res = n;
	while (n > 1) {
		n /= m;
		res += n;
	}
	cout << res << '\n';
}

// n개의 1달러 지폐를 m개씩 묶어 구성된 대로 셀 때, 지폐를 센 전체 횟수는?

// 우선 n회 세고, 묶어서(n을 m으로 나눠서) 나온 묶음 수(몫)만큼 세고, 그 과정을 한 묶음만 나올 때까지 반복