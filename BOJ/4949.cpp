// 균형잡힌 세상
// https://www.acmicpc.net/problem/4949

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	stack<char> st;
	string s;
	while (true) {
		getline(cin, s);
		if (s == ".")
			break;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(')
				st.push('(');
			else if (s[i] == '[')
				st.push('[');
			else if (s[i] == ')') {
				if (!st.empty() && st.top() == '(')
					st.pop();
				else {
					cout << "no" << endl;
					while (!st.empty())
						st.pop();
					break;
				}
			}
			else if (s[i] == ']') {
				if (!st.empty() && st.top() == '[')
					st.pop();
				else {
					cout << "no" << endl;
					while (!st.empty())
						st.pop();
					break;
				}
			}
			else if (s[i] == '.') {
				if (!st.empty()) {
					cout << "no" << endl;
					while (!st.empty())
						st.pop();
				}
				else
					cout << "yes" << endl;
				break;
			}
		}
	}
}