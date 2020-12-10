// Day 9: Recursion 3
// https://www.hackerrank.com/challenges/30-recursion/problem

using System;
using System.IO;

class Solution {

    // Complete the factorial function below.
    static int factorial(int n) {
        if (n <= 1)
            return 1;
        return n * factorial(n - 1);
    }

    static void Main(string[] args) {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int n = Convert.ToInt32(Console.ReadLine());

        int result = factorial(n);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}


// 재귀 함수로 팩토리얼 짜기
// factorial(n) = n * factorial(n - 1)
// (factorial(1) = 1)