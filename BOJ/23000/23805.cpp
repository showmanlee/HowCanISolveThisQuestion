// 골뱅이 찍기 - 돌아간 ㄹ
// https://www.acmicpc.net/problem/23805

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
			if (j / n == 0 || j / n == 2 || j / n == 4 || (i / n == 0 && j / n == 1) || (i / n == 4 && j / n == 3)) {
				cout << '@';
			}
			else {
				cout << ' ';
			}
		}
		cout << '\n';
	}
}

// 폭이 n인 반시계방향으로 90도 돌아간 ㄹ 찍기

// 지금까지의 골뱅이 찍기가 그랬던 것처럼 찍기 - 공백 넣어주면서