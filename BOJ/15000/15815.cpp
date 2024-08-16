// 천재 수학자 성필
// https://www.acmicpc.net/problem/15815

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    stack<int> st;
    for (char c : s) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int d = 0;
            if (c == '+') {
                d = (a + b);
            } else if (c == '-') {
                d = (b - a);
            } else if (c == '*') {
                d = (a * b);
            } else if (c == '/') {
                d = (b / a);
            }
            st.push(d);
        }
    }
    int res = st.top();
    st.pop();
    cout << res << '\n';
}

// 사칙연산을 괄호 없는 문자열로 나타냈을 때, 결과 출력하기

// 숫자가 나오면 스택에 넣고, 기호가 나오면 스택에서 숫자 2개를 빼서 연산한 뒤 결과를 스택에 넣는다
// 연산자 순서 체크에 주의