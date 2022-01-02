// 골뱅이 찍기 - ㅁ
// https://www.acmicpc.net/problem/23806

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
			if (i / n == 0 || i / n == 4 || j / n == 0 || j / n == 4) {
				cout << '@';
			}
			else {
				cout << ' ';
			}
		}
		cout << '\n';
	}
}

// 두께가 n인 ㅁ 그리기

// 기본적인 형태는 동일하고, 최종 크기는 n * 5
// 크기를 잡고, i/j 크기를 n으로 나눴을 때 0이나 4가 나올 경우 골뱅이를 출력한다