// Day 3: Intro to Conditional Statements
// https://www.hackerrank.com/challenges/30-conditional-statements/problem

using System;

class Solution {
    static void Main(string[] args) {
        int N = Convert.ToInt32(Console.ReadLine());
        
        if (N % 2 == 1)
            Console.WriteLine("Weird");
        else if (N >= 2 && N <= 5)
            Console.WriteLine("Not Weird");
        else if (N >= 6 && N <= 20)
            Console.WriteLine("Weird");
        else
            Console.WriteLine("Not Weird");
    }
}

// 조건문 만들기