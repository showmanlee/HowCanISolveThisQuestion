// I Speak TXTMSG
// https://www.acmicpc.net/problem/6841

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		string s, t;
		cin >> s;
		if (s == "CU") {
			t = "see you";
		} else if (s == ":-)") {
			t = "I’m happy";
		} else if (s == ":-(") {
			t = "I’m unhappy";
		} else if (s == ";-)") {
			t = "wink";
		} else if (s == ":-P") {
			t = "stick out my tongue";
		} else if (s == "(~.~)") {
			t = "sleepy";
		} else if (s == "TA") {
			t = "totally awesome";
		} else if (s == "CCC") {
			t = "Canadian Computing Competition";
		} else if (s == "CUZ") {
			t = "because";
		} else if (s == "TY") {
			t = "thank-you";
		} else if (s == "YW") {
			t = "you’re welcome";
		} else if (s == "TTYL") {
			t = "talk to you later";
		} else {
			t = s;
		}
		cout << t << '\n';
		if (s == "TTYL") {
			break;
		}
	}
}

// 주어진 문자열을 그대로 출력하되, 사전에 있는 문자열이면 대응하는 문자열로 변환하여 출력하기

// 사전 보고 그대로 바꿔서 출력해주기