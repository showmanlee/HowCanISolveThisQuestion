// 괄호
// acmicpc.net/problem/9012

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

bool VPS(string s) {
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			st.push('(');
		else {
			if (st.empty())
				return false;
			st.pop();
		}
	}
	if (st.empty())
		return true;
	return false;
}

int main(void) {
	int n;
	vector<string> ps;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		ps.push_back(s);
	}
	for (int i = 0; i < n; i++) 
		cout << (VPS(ps[i]) ? "YES" : "NO") << endl;
}