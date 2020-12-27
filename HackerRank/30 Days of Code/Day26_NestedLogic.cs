// Day 26: Nested Logic
// https://www.hackerrank.com/challenges/30-nested-logic/problem

using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    static void Main(String[] args) {
        string s = Console.ReadLine();
        int a = int.Parse(s.Split()[0]);
        int b = int.Parse(s.Split()[1]);
        int c = int.Parse(s.Split()[2]);
        s = Console.ReadLine();
        int x = int.Parse(s.Split()[0]);
        int y = int.Parse(s.Split()[1]);
        int z = int.Parse(s.Split()[2]);
        int res = 0;
        if (c > z)
            res = 10000;
        else if (b > y && c == z)
            res = 500 * (b - y);
        else if (a > x && b == y && c == z)
            res = 15 * (a - x);
        Console.WriteLine(res);
    }
}

// 주어진 문제 구현하기
// 복합 조건문 문제