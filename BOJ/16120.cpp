// PPAP
// https://www.acmicpc.net/problem/16120

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	string st;
	for (char c : s) {
		st += c;
		while (st.length() >= 4) {
			string v;
			for (int i = 0; i < 4; i++) {
				v = st.back() + v;
				st.pop_back();
			}
			if (v == "PPAP")
				st += "P";
			else {
				st += v;
				break;
			}
		}
	}
	cout << (st == "P" ? "PPAP" : "NP") << '\n';
}

// P는 PPAP 문자열이고, PPAP를 P로 치환한 문자열도 PPAP 문자열일 때, 주어진 문자열이 PPAP 문자열인지 판정하기

// 스택 원리 활용하기 - 한 글자씩 스택 역할의 문자열에 넣고, 스택 문자열의 끝이 PPAP가 되면 해당 형태를 P로 치환, 더 이상 치환되지 않을 때까지 반복
// 이렇게 돌린 후 최종적으로 P만 남으면 PPAP 문자열이 됨
// 이렇게 스택 형태로 string을 쓸 때는 substr보다는 back이나 pop_back을 활용하자 - substr은 n^2이 될 수도 있음