// 새로운 언어 CC
// https://www.acmicpc.net/problem/19945

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int ret = 1;
	if (n < 0) {
		ret = 32;
	} else if (n > 0) {
		ret = 0;
		while (n) {
			ret++;
			n /= 2;
		}
	}
	cout << ret << '\n';
}

// 주어진 int 정수를 비트로 표현했을 때의 길이 출력하기

// 음수는 무조건 32 - 부호가 붙으니까
// 0은 길이가 1
// 나머지 양수는 2로 계속 나눠서 길이 확인하기