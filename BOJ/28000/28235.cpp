// 코드마스터 2023
// https://www.acmicpc.net/problem/28235

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	if (s == "SONGDO") {
		cout << "HIGHSCHOOL";
	} else if (s == "CODE") {
		cout << "MASTER";
	} else if (s == "2023") {
		cout << "0611";
	} else if (s == "ALGORITHM") {
		cout << "CONTEST";
	}
}

// 주어진 문자열에 대응하는 문자열 출력하기