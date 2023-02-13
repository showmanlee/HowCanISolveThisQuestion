// 골뱅이 찍기 - 돌아간 ㅈ
// https://www.acmicpc.net/problem/23809

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n * 5; i++) {
		for (int j = 0; j < n * 5; j++) {
			if (j / n == 0 || ((j / n == 1 || j / n == 2) && i / n == 2) || (j / n == 3 && (i / n == 1 || i / n == 3)) || (j / n == 4 && (i / n == 0 || i / n == 4))) {
				cout << '@';
			} else if ((i / n == 0 || i / n == 4) || ((i / n == 1 || i / n == 3) && j / n < 3)) {
				cout << ' ';
			}
		} 
		cout << '\n';
	}
}

// 5n*5n 크기의 K 모양으로 별 찍기

// 흔한 별 찍기 문제 - 그대로 찍어줍시다, 공백 주의하면서