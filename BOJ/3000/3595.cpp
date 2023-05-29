// 맥주 냉장고
// https://www.acmicpc.net/problem/3595

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int resi = 0, resj = 0, resk = 0;
	long long resv = 98765432198765;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i * j > n) {
				break;
			}
			for (int k = 1; k <= n; k++) {
				if (i * j * k > n) {
					break;
				}
				if (i * j * k == n && i * j + j * k + i * k < resv) {
					resv = i * j + j * k + i * k;
					resi = i;
					resj = j;
					resk = k;
				}
			}
		}
	}
	cout << resi << ' ' << resj << ' ' << resk << '\n';
}

// 주어진 부피의 큐브를 만들기 위해 가로/세로/높이를 구할 떄, 겉넓이를 최소로 하는 길이 구하기

// 브루트포스로 구할 수 있는 범위 - 단, 계산 결과가 부피를 넘기면 멈춰야 함