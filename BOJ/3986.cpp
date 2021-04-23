// 좋은 단어
// https://www.acmicpc.net/problem/3986

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		stack<char> st;
		for (char c : s) {
			if (!st.empty() && st.top() == c)
				st.pop();
			else
				st.push(c);
		}	
		if (st.empty())
			res++;
	}
	cout << res << '\n';
}

// A와 B로 구성된 단어에서 같은 글자끼리 서로 이어 선들이 하나도 겹치지 않을 때 '좋은 단어'라고 할 때, 주어진 단어가 좋은 단어인가?
// A와 B로 보는 괄호 검사 문제 - 문자 스택 활용하기
// 문자열의 문자를 순회하며 스택이 비어있지 않고 스택 위의 문자가 현재 문자와 같으면 스택에서 하나 빼고, 그렇지 않으면 현재 문자를 넣어준다
// 그렇게 돌린 후 스택이 비어있으면 좋은 단어