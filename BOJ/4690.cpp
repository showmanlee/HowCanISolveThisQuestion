// 완전 세제곱
// https://www.acmicpc.net/problem/4690

#include <iostream>
using namespace std;

int main(void) {
	for (int a = 2; a <= 100; a++) {
		for (int b = 2; b <= a; b++) {
			for (int c = b; c <= a; c++) {
				for (int d = c; d <= a; d++) {
					int aaa = a * a * a;
					int bbb = b * b * b;
					int ccc = c * c * c;
					int ddd = d * d * d;
					if (aaa == bbb + ccc + ddd)
						cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
				}
			}
		}
	}
}

// 2~100까지인 자연수 a에 대해 a^3 = b^3 + c^3 + d^3을 만족하는 (b,c,d) 구하기
// n^4 브루트포스 - 생각보다 나오는게 많이 없음
// 그리고 이왕이면 헤더 함수보다는 직접 계산하는게 더 빠름