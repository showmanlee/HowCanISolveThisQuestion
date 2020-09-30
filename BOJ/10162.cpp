// 전자레인지
// https://www.acmicpc.net/problem/10162

#include <iostream>
using namespace std;

int main(void) {
	int a = 0, b = 0, c = 0, n;
	cin >> n;
	while (n > 0) {
		if (n >= 300) {
			n -= 300;
			a++;
		}
		else if (n >= 60) {
			n -= 60;
			b++;
		}
		else if (n >= 10) {
			n -= 10;
			c++;
		}
		else {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << a << ' ' << b << ' ' << c << endl;
	return 0;
}