// IBM 빼기 1
// https://www.acmicpc.net/problem/6321

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'Z')
				s[j] = 'A' - 1;
			s[j]++;
		}
		cout << "String #" << i << '\n' << s << "\n\n";
	}
}

// 알파벳 대문자로 구성된 문자열의 다음 문자로 구성된 문자열 출력하기