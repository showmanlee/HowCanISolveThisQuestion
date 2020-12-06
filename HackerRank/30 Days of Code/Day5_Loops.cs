// Day 5: Loops
// https://www.hackerrank.com/challenges/30-loops/problem

using System;

class Solution {
    static void Main(string[] args) {
        int n = Convert.ToInt32(Console.ReadLine());
        for (int i = 1; i <= 10; i++)
            Console.WriteLine(n + " x " + i + " = " + (n * i));
    }
}


// 반복문으로 구구단 출력