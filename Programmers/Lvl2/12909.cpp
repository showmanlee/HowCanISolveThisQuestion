// 올바른 괄호
// https://programmers.co.kr/learn/courses/30/lessons/12909

#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<bool> st;
    
    for(int i = 0; i < s.length(); i++){
        if (s[i] == '(')
            st.push(true);
        else{
            if (!st.empty() && st.top())
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}