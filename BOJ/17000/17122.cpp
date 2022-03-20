// 체스
// https://www.acmicpc.net/problem/17122

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string a, b;
		cin >> a >> b;
		int ax = a[0] - 'A';
		int ay = a[1] - '1';
		int bx = (stoi(b) - 1) % 8;
		int by = (stoi(b) - 1) / 8;
		bool res = !((ax % 2 == bx % 2) ^ (ay % 2 == by % 2));
		cout << (res ? "YES" : "NO") << '\n';
	}
}

// 체스판 칸을 알파벳+숫자나 번호로 표기한 결과가 주어졌을 떄, 두 칸의 색이 같은지 판정하기

// 각 칸의 행/열 번호를 구해서 두 칸의 행/열 홀짝이 모두 같거나 다르면 YES