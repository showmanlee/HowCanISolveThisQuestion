// 세금
// https://www.acmicpc.net/problem/20492

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	cout << (int)(n * 0.78) << ' ' << (int)((n * 0.8) + (n * 0.2 * 0.78)) << '\n';
}

// 전체의 22%를 뗄 때와 20%의 22%를 뗼 때 수령하는 금액은?
// 1000의 배수로 주어지기 때문에 소수 단위로 가지 않음