// 문자열 반복
// https://www.acmicpc.net/problem/2675

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int r;
		string c, s = "";
		cin >> r >> c;
		for (int j = 0; j < c.length(); j++) {
			for (int k = 0; k < r; k++)
				s += c[j];
		}
		cout << s << endl;
	}
}