// OIJ (OIJ)
// https://www.acmicpc.net/problem/33163

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	for (char& c : s) {
		if (c == 'J') {
			c = 'O';
		} else if (c == 'O') {
			c = 'I';
		} else if (c == 'I') {
			c = 'J';
		}
	}
	cout << s << '\n';
}

// J O I를 각각 O I J로 바꾸기