// Day 18: Queues and Stacks
// https://www.hackerrank.com/challenges/30-queues-stacks/problem

using System;
using System.Collections.Generic;
using System.IO;

class Solution {
    Stack<char> st = new Stack<char>();
    Queue<char> qu = new Queue<char>();
    
    public void pushCharacter(char c){
        st.Push(c);
    }
    public void enqueueCharacter(char c){
        qu.Enqueue(c);
    }
    public char popCharacter(){
        return st.Pop(); 
    }
    public char dequeueCharacter(){
        return qu.Dequeue();
    }


    static void Main(String[] args) {
        // read the string s.
        string s = Console.ReadLine();
        
        // create the Solution class object p.
        Solution obj = new Solution();
        
        // push/enqueue all the characters of string s to stack.
        foreach (char c in s) {
            obj.pushCharacter(c);
            obj.enqueueCharacter(c);
        }
        
        bool isPalindrome = true;
        
        // pop the top character from stack.
        // dequeue the first character from queue.
        // compare both the characters.
        for (int i = 0; i < s.Length / 2; i++) {
            if (obj.popCharacter() != obj.dequeueCharacter()) {
                isPalindrome = false;
                
                break;
            }
        }
        
        // finally print whether string s is palindrome or not.
        if (isPalindrome) {
            Console.Write("The word, {0}, is a palindrome.", s);
        } else {
            Console.Write("The word, {0}, is not a palindrome.", s);
        }
    }
}

// 스택과 큐를 이용해 펠린드롬 확인하기(스택과 큐에 문자들을 집어넣고 뺀 결과가 모두 같으면 펠린드롬)
// Stack<char> st = new Stack<char>(), st.Push(1), st.Pop();
// Queue<char> qu = new Queue<char>(), qu.Enqueue(1), qu.Dequeue();