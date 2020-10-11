// OX퀴즈
// https://www.acmicpc.net/problem/8958

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int combo = 0, score = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'O') {
				combo++;
				score += combo;
			}
			else
				combo = 0;
		}
		cout << score << endl;
	}
}