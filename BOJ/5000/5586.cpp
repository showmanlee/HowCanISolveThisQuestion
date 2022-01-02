// JOI와 IOI
// https://www.acmicpc.net/problem/5586

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int joi = 0, ioi = 0;
	for (int i = 0; i < s.length() - 2; i++) {
		if (s.substr(i, 3) == "JOI")
			joi++;
		else if (s.substr(i, 3) == "IOI")
			ioi++;
	}
	cout << joi << '\n' << ioi << '\n';
}

// 문자열에 등장하는 JOI와 IOI의 개수 구하기

// 문자열이 XOXOXOXOX 형태로 주어지지 않으니, 처음부터 끝까지 윈도우를 움직이며 JOI와 IOI가 등장할 때마다 세어주기
// 문자열 길이가 10000까지이므로 세어줄 수 있음