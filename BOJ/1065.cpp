// 한수
// https://www.acmicpc.net/problem/1065

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n, res = 0;
	cin >> n;
	if (n < 100)
		res = n;
	else {
		res = 99;
		for (int i = 100; i <= n; i++) {
			string s = to_string(i);
			int diff = s[0] - s[1];
			if (s[1] - s[2] != diff)
				continue;
			res++;
		}
	}
	cout << res << endl;
}

// 1~2자리수는 모두 한수, 3자리수만 어떻게 해주면 됨
// 범위가 1000까지긴 하지만 1000은 어차피 한수가 아니기 때문에 특별한 핸들링 필요 없음