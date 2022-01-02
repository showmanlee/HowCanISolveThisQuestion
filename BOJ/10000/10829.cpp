// 이진수 변환
// https://www.acmicpc.net/problem/10829

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	string res;
	while (n != 0) {
		res = to_string(n % 2) + res;
		n /= 2;
	}
	cout << res << '\n';
}

// long long 범위의 십진수를 이진수로 출력하기

// 일반적인 이진수 변환 기법 사용하기 - n이 0이 될 때까지 n%2의 결과를 앞에 붙이고, n을 2로 나누는 연산 반복