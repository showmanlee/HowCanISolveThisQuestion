// 탕수육
// https://www.acmicpc.net/problem/13419

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.length() == 1) {
			cout << s << '\n' << s << '\n';
			continue;
		}
		int idx1 = 0, idx2 = 1;
		string s1, s2;
		while (true) {
			if (s1.length() != 0 && s[idx1] == s1[0])
				break;
			s1 += s[idx1];
			idx1 = (idx1 + 2) % s.length();
		}
		while (true) {
			if (s2.length() != 0 && s[idx2] == s2[0])
				break;
			s2 += s[idx2];
			idx2 = (idx2 + 2) % s.length();
		}
		cout << s1 << '\n' << s2 << '\n';
	}
}

// 2인용 탕수육 게임을 알파벳으로 할 때, 자기 차례에 말해야 하는 글자들을 반복을 최소화하여 출력하기
// 한쪽은 0, 한쪽은 1부터 두 칸씩 읽기 시작해 반복이 시작되면(첫 글자가 다시 등장한 경우) 중단
// 입력된 알파벳인 한 글자인 경우 그것만 부르기