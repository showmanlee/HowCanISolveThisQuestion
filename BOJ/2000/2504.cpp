// 괄호의 값
// https://www.acmicpc.net/problem/2504

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	bool fail = false;
	int res = 0, temp = 1;
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (c == '(') {
			st.push(c);
			temp *= 2;
		}
		else if (c == '[') {
			st.push(c);
			temp *= 3;
		}
		else if (c == ')') {
			if (st.empty()) {
				fail = true;
				break;
			}
			if (st.top() == '(') {
				if (s[i - 1] != ']' && s[i - 1] != ')')
					res += temp;
				st.pop();
			}
			else {
				fail = true;
				break;
			}
			temp /= 2;
		}
		else if (c == ']') {
			if (st.empty()) {
				fail = true;
				break;
			}
			if (st.top() == '[') {
				if (s[i - 1] != ']' && s[i - 1] != ')')
					res += temp;
				st.pop();
			}
			else {
				fail = true;
				break;
			}
			temp /= 3;
		}
	}
	if (fail || !st.empty())
		res = 0;
	cout << res << '\n';
}

// 소괄호와 대괄호가 섞인 문자열에서 ()는 *2, []는 *3일 때, 문자열의 점수 출력하기
// 스택을 이용한 괄호 처리
// ()()처럼 닫힌 괄호가 옆에 있으면 +도 한다 - 곱하기를 모으는 temp와 이를 더해주는 res를 분리
// 문자를 순서대로 순회하면서 여는 괄호가 나오면 temp에 곱해주고 stack에 push
// 닫는 괄호가 나왔는데 스택이 비어 있거나 대응하지 않는 괄호가 스택 위에 있는 경우 fail
// 스택에서 대응하는 괄호가 나왔는데 이전에 여는 괄호가 나왔으면 이제까지 나온 temp를 res에 추가, 이후 temp를 나눠주기
// 어차피 괄호가 모두 닫히면 temp는 다시 1이 된다
// 앞으로 괄호 문제 나오면 쩔쩔매지 않게 잘 보고 체득합시다
// 괄호 열 때는 스택에 넣고, 괄호 닫을 때 스택을 보고 비어있거나 다른 괄호가 있으면 탈락