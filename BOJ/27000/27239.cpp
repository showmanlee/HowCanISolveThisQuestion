// Шахматная доска
// https://www.acmicpc.net/problem/27239

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	n--;
	cout << (char)('a' + (n % 8)) << (n / 8 + 1) << '\n';
}

// a1부터 h8까지 순서대로 1부터 64까지 적은 8*8 보드에서 적은 숫자가 주어졌을 때 칸 번호 구하기

// 행은 *8, 열은 *1 - -1한 뒤 몫과 나머지로 구하기