// 숫자 빈도 수
// https://www.acmicpc.net/problem/14912

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n, d;
	cin >> n >> d;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		string s = to_string(i);
		for (char c : s)
			if (c == d + '0')
				res++;
	}
	cout << res << '\n';
}

// 1부터 n까지 썼을 때 특정 숫자의 등장 횟수 출력하기
// 1부터 n까지 돌리면서 string으로 숫자 세기