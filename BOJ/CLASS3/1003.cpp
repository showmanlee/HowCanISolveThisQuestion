// 피보나치 함수
// https://www.acmicpc.net/problem/1003

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int pib[41];
	int n;
	pib[0] = 0;
	pib[1] = 1;
	for (int i = 2; i <= 40; i++)
		pib[i] = pib[i - 2] + pib[i - 1];
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p == 0)
			cout << "1 0" << '\n';
		else if (p == 1)
			cout << "0 1" << '\n';
		else
			cout << pib[p - 1] << ' ' << pib[p] << '\n';
	}
}

// 진짜 재귀함수를 돌려보라는 소리가 아니라 재귀함수 돌린 걸 시뮬레이션하라는 소리
// 2 -> 1 0								// 1 1
// 3 -> 2 1 1 0							// 2 1
// 4 -> 3 2 2 1 1 0 1 0					// 3 2
// 5 -> 4 3 3 2 2 1 1 0 1 0 2 1 1 0		// 5 3
// 1과 0의 등장 개수도 피보나치 - 1 = n항, 0 = n-1항
// 단, 1과 0이 나온 경우 처리 필요