// Day 18: Queues and Stacks
// https://www.hackerrank.com/challenges/30-queues-stacks/problem

import java.io.*;
import java.util.*;

public class Solution {
    
    Stack<Character> st = new Stack<>();
    Queue<Character> qu = new LinkedList<>();
    
    public void pushCharacter(char c){
        st.push(c);
    }
    public void enqueueCharacter(char c){
        qu.add(c);
    }
    public char popCharacter(){
        return st.pop(); 
    }
    public char dequeueCharacter(){
        return qu.poll();
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String input = scan.nextLine();
        scan.close();

        // Convert input String to an array of characters:
        char[] s = input.toCharArray();

        // Create a Solution object:
        Solution p = new Solution();

        // Enqueue/Push all chars to their respective data structures:
        for (char c : s) {
            p.pushCharacter(c);
            p.enqueueCharacter(c);
        }

        // Pop/Dequeue the chars at the head of both data structures and compare them:
        boolean isPalindrome = true;
        for (int i = 0; i < s.length/2; i++) {
            if (p.popCharacter() != p.dequeueCharacter()) {
                isPalindrome = false;                
                break;
            }
        }

        //Finally, print whether string s is palindrome or not.
        System.out.println( "The word, " + input + ", is " 
                           + ( (!isPalindrome) ? "not a palindrome." : "a palindrome." ) );
    }
}

// 스택과 큐를 이용해 펠린드롬 확인하기(스택과 큐에 문자들을 집어넣고 뺀 결과가 모두 같으면 펠린드롬)
// Stack<Character> st = new Stack<>(), st.push(1), st.pop();
// Queue<Character> qu = new LinkedList<>(), qu.add(1), qu.poll();