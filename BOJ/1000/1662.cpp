// 압축
// https://www.acmicpc.net/problem/1662

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	stack<int> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(-1);
		} else if (s[i] == ')') {
			int p = 0;
			while (st.top() != -1) {
				p += st.top();
				st.pop();
			}
			st.pop();
			p *= st.top();
			st.pop();
			st.push(p);
		} else {
			if (i < s.length() - 1 && s[i + 1] == '(') {
				st.push(s[i] - '0');
			} else {
				st.push(1);
			}
		}
	}
	int res = 0;
	while (!st.empty()) {
		res += st.top();
		st.pop();
	}
	cout << res << '\n';
}

// 괄호 앞 숫자만큼 괄호 안 문자열을 반복하는 압축 문자열의 압축 해제 길이 구하기