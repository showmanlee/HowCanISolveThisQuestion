// 별 찍기 - 15
// https://www.acmicpc.net/problem/10990

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++)
			cout << ' ';
		cout << '*';
		if (i != 0) {
			for (int j = 0; j < i * 2 - 1; j++)
				cout << ' ';
			cout << '*';
		}
		cout << '\n';
	}
}

// 별을 높이가 n인 ㅅ 모양으로 출력하기