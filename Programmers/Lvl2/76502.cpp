// 괄호 회전하기
// https://programmers.co.kr/learn/courses/30/lessons/76502

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    for (int t = 0; t < s.length(); t++){
        stack<char> st;
        bool fail = false;
        for (char c : s){
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else if (c == ')'){
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    fail = true;
            }
            else if (c == ']'){
                if (!st.empty() && st.top() == '[')
                    st.pop();
                else
                    fail = true;
            }
            else if (c == '}'){
                if (!st.empty() && st.top() == '{')
                    st.pop();
                else
                    fail = true;
            }
            if (fail)
                break;
        }
        if (!st.empty())
            fail = true;
        if (!fail)
            answer++;
        s = s.substr(1) + s[0];
    }
    return answer;
}

// 소/중/대괄호로 구성된 문자열이 주어졌을 때, 해당 문자열과 문자들을 한 칸씩 회전한 문자열들 중 올바른 괄호 문자열의 수는?
// 흔한 스택을 이용한 괄호 판정 문제 - 다만 문자열 회전을 곁들인
// 틀린 괄호가 되는 시점 - 닫는 괄호가 등장했을 때 스택이 비어있거나 스택 위에 해당 괄호에 대응하는 괄호가 없는 경우 / 문자열 순회를 마쳤는데 스택이 비어있지 않은 경우