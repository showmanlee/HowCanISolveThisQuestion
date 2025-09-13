// 조약돌	
// https://www.acmicpc.net/problem/2097

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	if (n <= 2) {
		res = 4;
	} else {
		int p = sqrt(n) + 0.5;
		if (p * p >= n) {
			res = (p - 1) * 4;
		} else {
			res = ((p - 1) * 2) + (p * 2);
		}
	}
	cout << res << '\n';
}

// n개의 돌을 2차원 좌표 위에 올릴 떄, 돌들을 두르는 직사각형의 최소 둘레 출력하기