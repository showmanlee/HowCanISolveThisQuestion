// 약수 구하기
// https://www.acmicpc.net/problem/2501

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int res = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			cnt++;
			if (cnt == k) {
				res = i;
				break;
			}
		}
	}
	cout << res << '\n';
}

// n의 k번째 약수 구하기

// 약수는 O(n)으로 풀 수 있음
// 만약 k번째 약수가 없을 경우 0 출력하기 - 이를 위해 약수 개수 세주기