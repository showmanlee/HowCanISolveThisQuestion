// 스키테일 암호
// https://www.acmicpc.net/problem/23080

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
	for (int i = 0; i < s.length(); i++) {
		if (i % n == 0) {
			cout << s[i];
		}
	}
	cout << '\n';
}

// 글자 n개를 담을 수 있는 막대에 테이프를 둘러 테이프 앞부분부터 막대에 일렬로 글자를 쓰고 그 외의 부분엔 아무 글자나 써서 암호를 만들 때, 해독한 결과는?

// 첫 글자부터 매 n글자마다 읽어주면 OK