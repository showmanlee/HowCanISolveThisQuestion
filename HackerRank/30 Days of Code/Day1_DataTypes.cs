// Day 1: Data Types
// https://www.hackerrank.com/challenges/30-data-types/problem

using System;
using System.Collections.Generic;
using System.IO;

class Solution {
    static void Main(String[] args) {
        int i = 4;
        double d = 4.0;
        string s = "HackerRank ";

        int j = int.Parse(Console.ReadLine());
        double e = double.Parse(Console.ReadLine());
        string t = Console.ReadLine();
        Console.WriteLine(i + j);
        Console.WriteLine("{0:f1}", d + e);
        Console.WriteLine(s + t);
    }
}


// 정수형, 실수형, 문자열을 입력받고 미리 만들어진 변수와 더하기/붙이기
// C#에서 실수형 출력 정확도 설정은 저러한 포매팅 방식으로 사용(f는 고정 소수점)