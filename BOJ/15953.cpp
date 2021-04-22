// 상금 헌터
// https://www.acmicpc.net/problem/15953

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int a, b;
		cin >> a >> b;
		int res = 0;
		if (a == 1)
			res += 5000000;
		else if (a == 2 || a == 3)
			res += 3000000;
		else if (a >= 4 && a <= 6)
			res += 2000000;
		else if (a >= 7 && a <= 10)
			res += 500000;
		else if (a >= 11 && a <= 15)
			res += 300000;
		else if (a >= 16 && a <= 21)
			res += 100000;
		if (b == 1)
			res += 5120000;
		else if (b == 2 || b == 3)
			res += 2560000;
		else if (b >= 4 && b <= 7)
			res += 1280000;
		else if (b >= 8 && b <= 15)
			res += 640000;
		else if (b >= 16 && b <= 31)
			res += 320000;
		cout << res << '\n';
	}
}

// 상금 지급 기준이 다른 2개의 대회에서 받았다고 가정한 성적들이 주어질 때, 얻을 수 있는 상금은?
// 문제의 조건문을 보고 결과에 누적해주기