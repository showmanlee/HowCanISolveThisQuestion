// 최댓값
// https://www.acmicpc.net/problem/2562

#include <iostream>
using namespace std;

int main(void) {
	int n[9];
	int max = 0;
	for (int i = 0; i < 9; i++) {
		cin >> n[i];
		if (n[max] < n[i])
			max = i;
	}
	cout << n[max] << '\n' << max + 1 << endl;
}
// 무조건 숫자 9개