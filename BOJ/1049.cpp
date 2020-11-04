// 기타줄
// https://www.acmicpc.net/problem/1049

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m, six = 1001, one = 1001;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, o;
		cin >> s >> o;
		if (s < six)
			six = s;
		if (o < one)
			one = o;
	}
	int r[3] = { (six * (n / 6)) + (one * (n % 6)), one * n, six * (n / 6 + 1) };
	sort(r, r + 3);
	cout << r[0] << '\n';	
}

// 가능한 가격 경우의 수가 3가지임에 유의
// 1. 모두 낱개로 살 경우
// 2. 묶음으로 산 뒤 남은 줄을 낱개로 살 경우
// 3. 묶음으로만 살 경우