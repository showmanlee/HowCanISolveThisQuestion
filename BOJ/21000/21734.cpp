// SMUPC의 등장
// https://www.acmicpc.net/problem/21734

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	for (char c : s) {
		int p = c / 100 + (c / 10 % 10) + c % 10;
		for (int i = 0; i < p; i++)
			cout << c;
		cout << '\n';
	}
}

// 소문자로 구성된 문자열에서 각 문자의 아스키 코드 값 자릿수의 합만큼 해당 문자 출력하기 
// 'a'~'z' = 97~122 - 따라서 세 자리를 체크해줘야 함에 주의