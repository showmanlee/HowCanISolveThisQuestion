// Balanced Brackets
// https://www.hackerrank.com/challenges/balanced-brackets/problem

string isBalanced(string s) {
    stack<char> st;
    if (s.find("[") != string::npos && s.find("]") == string::npos)
        return "NO";
    if (s.find("(") != string::npos && s.find(")") == string::npos)
        return "NO";
    if (s.find("{") != string::npos && s.find("}") == string::npos)
        return "NO";

    for (int i = 0; i < s.length(); i++){
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')'){
            while(!st.empty() && st.top() != '(')
                st.pop();
            if (st.empty())
                return "NO";
            st.pop();
        }
        else if (s[i] == ']'){
            while(!st.empty() && st.top() != '[')
                st.pop();
            if (st.empty())
                return "NO";
            st.pop();
        } 
        else if (s[i] == '}'){
            while(!st.empty() && st.top() != '{')
                st.pop();
            if (st.empty())
                return "NO";
            st.pop();
        }
    }
    if (st.empty())
        return "YES";
    else
        return "NO";
}

// 소/중/대괄호가 적절한지 확인
// 여는 괄호는 있는데 닫는 괄호가 없는지부터 확인해야 스택을 정확히 돌릴 수 있더라