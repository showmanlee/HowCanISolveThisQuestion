// 피노키오
// https://www.acmicpc.net/problem/12866

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	long long a = 0, c = 0, g = 0, t = 0;
	for (char h : s) {
		if (h == 'A') {
			a++;
		}
		if (h == 'C') {
			c++;
		}
		if (h == 'G') {
			g++;
		}
		if (h == 'T') {
			t++;
		}
			
	}
	a = (a * c) % 1000000007;
	a = (a * g) % 1000000007;
	a = (a * t) % 1000000007;
	cout << a << '\n';
}

// 주어진 문자열로 만들 수 있는 ACGT의 개수 구하기