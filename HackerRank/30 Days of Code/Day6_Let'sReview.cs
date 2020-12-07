// Day 6: Let's Review
// https://www.hackerrank.com/challenges/30-review-loop/problem

using System;
using System.Collections.Generic;
using System.IO;

class Solution {
    static void Main(String[] args) {
        int n = Convert.ToInt32(Console.ReadLine());
        for (int i = 0; i < n; i++){
            string s = Console.ReadLine();
            for (int j = 0; j < s.Length; j += 2)
                Console.Write(s[j]);
            Console.Write(" ");
            for (int j = 1; j < s.Length; j += 2)
                Console.Write(s[j]);
            Console.Write("\n");
        }
    }
}


// 1주차(입출력, 조건문, 반복문) 복습
// 문자열을 입력받고 짝수 번째 글자와 홀수 번째 글짜 따로 출력하기