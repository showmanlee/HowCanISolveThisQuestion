// Day 25: Running Time and Complexity
// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem

using System;
using System.Collections.Generic;
using System.IO;

class Solution {
    public static bool isPrime(int n){
        if (n == 1)
            return false;
        for (int i = 2; i <= Math.Sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }
    
    static void Main(String[] args) {
        int t = int.Parse(Console.ReadLine());
        for (int i = 0; i < t; i++){
            int n = int.Parse(Console.ReadLine());
            if (isPrime(n))
                Console.WriteLine("Prime");
            else
                Console.WriteLine("Not prime");
        }
    }
}

// 소수 알고리즘 짜는데, O(n^2)가 나오지 않게 하기
// sqrt(n)까지 계산해도 됨