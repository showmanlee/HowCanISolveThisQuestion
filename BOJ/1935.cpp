// 후위 표기식2
// https://www.acmicpc.net/problem/1935

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<double> operand(n);
	for (int i = 0; i < n; i++)
		cin >> operand[i];
	stack<double> st;
	for (char c : s) {
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			double o2 = st.top();
			st.pop();
			double o1 = st.top();
			st.pop();
			if (c == '+')
				st.push(o1 + o2);
			else if (c == '-')
				st.push(o1 - o2);
			else if (c == '*')
				st.push(o1 * o2);
			else if (c == '/')
				st.push(o1 / o2);
		}
		else
			st.push(operand[c - 'A']);
	}
	cout << fixed;
	cout.precision(2);
	cout << st.top() << '\n';
}

// 피연산자가 알파벳으로 나타난 후위 표기식과 알파벳에 대응하는 수가 주어졌을 때, 계산 결과 출력하기

// 후위 표기식 - 스택을 활용하여 계산할 수 있는 식
// 식을 차례대로 순회하다가 피연산자가 나온 경우 스택에 넣고, 연산자가 나온 경우 스택 위의 두 수를 빼서 연산한 뒤 다시 스택에 넣는다 - 결과는 마지막에 스택에 남는 수
// 주어지는 피연산자값들을 별도의 배열에 저장한 뒤, 피연산자가 나오면 문자를 이용해 인덱스를 추출하여 스택에 넣는다
// 연산자로 연산할 때 피연산자를 뽑는 순서에 주의 - o1, o2라고 할 때 o2, o1 순으로 뽑아짐