// Day 16: Exceptions - String to Integer
// https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {

    static void Main(String[] args) {
        string S = Console.ReadLine();
        try{
            Console.WriteLine(int.Parse(S));
        }
        catch{
            Console.WriteLine("Bad String");
        }
    }
}

// 예외 처리로 숫자만 있는 문자열 구분하기
// try... catch