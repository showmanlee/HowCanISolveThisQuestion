// 팰린드롬수
// https://www.acmicpc.net/problem/1259

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	while (true) {
		string s;
		cin >> s;
		if (s == "0")
			break;
		if (s.length() == 1)
			cout << "yes" << endl;
		else {
			bool p = true;
			for (int i = 0; i < s.length() / 2; i++)
				if (s[i] != s[s.length() - i - 1])
					p = false;
			cout << (p ? "yes" : "no") << endl;
		}
	}
}