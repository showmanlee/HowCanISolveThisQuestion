// Day 18: Queues and Stacks
// https://www.hackerrank.com/challenges/30-queues-stacks/problem

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    stack<char> st;
    queue<char> qu;
    
public:
    void pushCharacter(char c){
        st.push(c);
    }
    void enqueueCharacter(char c){
        qu.push(c);
    }
    char popCharacter(){
        char c = st.top();
        st.pop();
        return c;
    }
    char dequeueCharacter(){
        char c = qu.front();
        qu.pop();
        return c;
    }
};

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}

// 스택과 큐를 이용해 펠린드롬 확인하기(스택과 큐에 문자들을 집어넣고 뺀 결과가 모두 같으면 펠린드롬)
// stack<char> st, st.push(1), st.top(), st.pop();
// queue<char> qu, qu.push(1), qu.front(), qu.pop();