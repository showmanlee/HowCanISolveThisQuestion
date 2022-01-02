// 후위 표기식
// https://www.acmicpc.net/problem/1918

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	stack<char> st;
	for (char c : s) {
		if (c == '(')
			st.push(c);
		else if (c == ')') {
			while (!st.empty() && st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else if (c == '*' || c == '/') {
			while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
				cout << st.top();
				st.pop();
			}
			st.push(c);
		}
		else if (c == '+' || c == '-') {
			while (!st.empty() && st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.push(c);
		}
		else
			cout << c;
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	cout << '\n';
}

// 괄호도 있는 중위 표기 수식을 후위 표기식으로 변환하기
// 스택을 활용한 수식 변환 문제는 학교에서도 배우고 문제에서도 나오는 문제들

// 우선 피연산자들은 무조건 결과식에 표시하고, 연산자들은 다음의 조건에 따라 스택에 넣고 뺀다
// ( : 발견 즉시 스택에 넣는다
// ) : 발견 즉시 스택에 (가 나올 때까지 나온 연산자를 출력하며 뺀다
// */ : 현재 스택 위에 있는 연산자가 */가 아닐 때까지 스택의 연산자를 출력하며 빼고 현재 연산자를 넣는다
// +- : 현재 스택 위에 있는 연산자가 +-*/가 아닐 때까지 스택의 연산자를 출력하며 빼고 현재 연산자를 넣는다
// 모든 연산자 순회를 마치면 남은 연산자들을 모두 출력한다

// 이런 문제에서는 우선순위 컨트롤이 중요 - 스택에서 자신 위에 우선순위가 낮은 연산자를 둬서는 안 된다