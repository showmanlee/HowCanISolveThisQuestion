// 과자
// https://www.acmicpc.net/problem/10156

#include <iostream>
using namespace std;

int main(void) {
	int k, n, m;
	cin >> k >> n >> m;
	cout << (k * n - m > 0 ? k * n - m : 0) << '\n';
}

// 사고 싶은 과자의 가격과 개수, 그리고 수중의 돈이 주어질 때, 엄마에게 추가로 받아야 하는 돈은?
// k * n - m, 결과가 음수일 경우 0 출력