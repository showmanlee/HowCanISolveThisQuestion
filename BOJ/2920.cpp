// 음계
// https://www.acmicpc.net/problem/2920

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	getline(cin, s);
	if (s == "1 2 3 4 5 6 7 8")
		cout << "ascending" << endl;
	else if (s == "8 7 6 5 4 3 2 1")
		cout << "descending" << endl;
	else
		cout << "mixed" << endl;
}

// 어차피 음계가 8개고 8개를 치라고 나왔으니 ascending, descending는 하나씩밖에 없음
