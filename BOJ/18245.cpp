// 이상한 나라의 암호
// https://www.acmicpc.net/problem/18245

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int cnt = 1;
	while (true) {
		string s;
		getline(cin, s);
		if (s == "Was it a cat I saw?")
			break;
		for (int i = 0; i < s.length(); i += cnt + 1)
			cout << s[i];
		cout << '\n';
		cnt++;
	}
}

// 여러 줄의 문자열들을 받고, n번째 문자열을 첫 글자부터 n개씩 띄어 읽은 결과 출력하기
// 줄 수를 세어주면서, 받은 문자열의 (줄 + 1) 간격의 문자만 출력하기