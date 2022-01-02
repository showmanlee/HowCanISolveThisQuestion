// UCPC는 무엇의 약자일까?
// https://www.acmicpc.net/problem/15904

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
	string n, p = "";
	getline(cin, n);

	for (int i = 0; i < n.length(); i++)
		if (isupper(n[i]))
			p += n[i];

	if (p.length() < 4) {
		cout << "I hate UCPC" << endl;
		return 0;
	}

	int index = 0;
	string ucpc = "UCPC";
	for (int i = 0; i < p.length(); i++) {
		if (index == 3 && p[i] == ucpc[index]) {
			cout << "I love UCPC" << endl;
			return 0;
		}
		if (p[i] == ucpc[index]) 
			index++;
	}
	
	cout << "I hate UCPC" << endl;
}