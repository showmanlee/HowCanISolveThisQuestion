// Day 28: RegEx, Patterns, and Intro to Databases
// https://www.hackerrank.com/challenges/30-regex-patterns/problem

using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Solution {
    static void Main(string[] args) {
        int N = Convert.ToInt32(Console.ReadLine());
        List<string> res = new List<string>();
        for (int NItr = 0; NItr < N; NItr++) {
            string[] firstNameEmailID = Console.ReadLine().Split(' ');
            string firstName = firstNameEmailID[0];
            string emailID = firstNameEmailID[1];
            if (emailID.Split('@')[1] == "gmail.com")
                res.Add(firstName);
        }
        res.Sort();
        foreach (string s in res)
            Console.WriteLine(s);
    }
}


// 정규 표현식 또는 split을 통한 데이터 추출
// gmail.com 이메일을 가지고 있는 사람의 이름을 오름차순으로 표시