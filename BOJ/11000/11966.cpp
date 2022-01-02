// 2의 제곱인가?
// https://www.acmicpc.net/problem/11966

#include <iostream>
using namespace std;

int main(void) {
	int n, count = 1, res = 0;
	cin >> n;
	for (int i = 0; i <= 30; i++) {
		if (n == count) {
			res = 1;
			break;
		}
		else if (n < count)
			break;
		count *= 2;
	}
	cout << res << '\n';
}

// 입력받은 수가 2의 제곱수라면 1, 아니면 0 출력하기
// 어차피 입력값 최대가 2^30이고 숫자 하나만 받으니까 2^0~2^30과 일일히 비교해도 됨