// 피갤컵
// https://www.acmicpc.net/problem/33612

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	n--;
	int a = 2024, b = 7 + (n * 7);
	a += (b / 12);
	b %= 12;
	b++;
	cout << a << ' ' << b << '\n';
}

// 2024년 8월부터 7개월마다 열리는 행사의 제n회 개최월 구하기