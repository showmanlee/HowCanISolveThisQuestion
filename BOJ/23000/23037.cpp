// 5의 수난
// https://www.acmicpc.net/problem/23037

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < 5; i++) {
		int a = n % 10;
		res += a * a * a * a * a;
		n /= 10;
	}
	cout << res << '\n';
}

// 다섯 자리 수의 각 자릿수의 다섯제곱 합 구하기

// 다섯 자리 수를 받고, 각 자릿수에 대해 다섯제곱을 해서 누적시켜서 결과값으로 출력
// 간단하네

// 그나저나 월요일에 실수로 커밋을 안 해서 거의 1년 스트릭이 끊겨버렸다
// 하지만 매일이 중요한 것이 아니라 꾸준함이 중요하기에...