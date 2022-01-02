// 큰 수 A+B (2)
// https://www.acmicpc.net/problem/15353

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	string a, b, res = "";
	cin >> a >> b;
	if (a.length() < b.length())
		swap(a, b);
	int al = a.length();
	int bl = al - b.length();
	bool up = false;
	for (int i = al - 1; i >= 0; i--) {
		int n = 0;
		if (i - bl >= 0)
			n += (a[i] - '0') + (b[i - bl] - '0');
		else
			n += (a[i] - '0');
		if (up)
			n++;
		up = n >= 10;
		n %= 10;
		res = to_string(n) + res;
	}
	if (up)
		res = "1" + res;
	cout << res << '\n';
}

// 10^10000 미만의 정수 사이의 덧셈을 C++에서 구현하세요
// 이 정도 수는 long long에서도 못하기 때문에 문자열 상에서 구현해야 함