// 공사장 표지판
// https://www.acmicpc.net/problem/23055

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || i == 0 || i == n - 1 || j == 0 || j == n - 1 || i + j == n - 1)
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
}

// n*n 크기의 x자 표지판 모양으로 별 찍기

// i, j 좌표가 0 또는 n - 1이거나, i == j거나, i + j가 n - 1일 경우 찍어주기