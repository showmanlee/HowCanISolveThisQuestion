// 숫자 놀이
// https://www.acmicpc.net/problem/2777

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		int res = 0;
		for (int i = 9; i >= 2; i--) {
			while (n % i == 0) {
				res++;
				n /= i;
			}
		}
		cout << (n == 1 ? res : -1) << '\n';
	}
}

// 자릿수를 모두 곱할 때 n이 나오는 정수 중 가장 작은 정수의 길이 구하기

// 최대한 자릿수가 적은 정수를 만들려면 각 자리에 최대한 높은 수를 넣어야 함
// 여기서는 가장 작은 '정수'가 아닌 '길이'만 구하면 되므로 9부터 2까지 최대한 나눈 후 나누어떨어지는지 확인한다
// 탐색 범위에 1까지 포함할 경우 무한루프에 빠지므로 주의