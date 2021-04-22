// Fan Death
// https://www.acmicpc.net/problem/15633

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (n % i == 0)
			res += i;
	res = res * 5 - 24;
	cout << res << '\n';
}

// n의 모든 약수의 합에 5를 곱하고 24를 뺀 값 출력하기
// n이 10000까지이기 때문에 반복문으로 충분히 찾을 수 있다
// 광고 차단 프로그램을 꺼야 문제가 온전히 보임에 주의