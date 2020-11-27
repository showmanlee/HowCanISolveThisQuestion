// 상근날드
// https://www.acmicpc.net/problem/5543

#include <iostream>
using namespace std;

int main(void) {
	int burger = 2100, bev = 2100, a;
	for (int i = 0; i < 3; i++) {
		cin >> a;
		if (a < burger)
			burger = a;
	}
	for (int i = 0; i < 2; i++) {
		cin >> a;
		if (a < bev)
			bev = a;
	}
	cout << (burger + bev - 50) << "\n";
}

// 버거 3개와 음료 2개 중 하나씩을 고른 후 거기서 50원을 빼면 세트 가격
// 3개 중 가장 싼 것 + 2개 중 가장 싼 것 - 50 = res