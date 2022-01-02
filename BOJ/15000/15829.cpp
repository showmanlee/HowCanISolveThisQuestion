// Hashing
// https://www.acmicpc.net/problem/15829

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	string s;
	long long hash = 0;
	long long pow = 1;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		hash = (hash + (s[i] - 'a' + 1) * pow) % 1234567891;
		pow = (pow * 31) % 1234567891;
	}
	cout << hash << '\n';
}

// 나머지 연산 중 오버플로 방지를 위한 long long 처리
// 어차피 n번 만큼 반복을 돌기 때문에 pow를 사용할 필요 없이 곱하는 수(나머지 연산)