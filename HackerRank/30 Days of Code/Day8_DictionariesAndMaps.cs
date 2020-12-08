// Day 8: Dictionaries and Maps
// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem
using System;
using System.Collections.Generic;
using System.IO;

class Solution {
    static void Main(String[] args) {
        Dictionary<string, int> dict = new Dictionary<string, int>();
        int n = int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++){
            string[] ss = Console.ReadLine().Split();
            dict.Add(ss[0], int.Parse(ss[1]));
        }
        while (true){
            try {
            string s = Console.ReadLine();
            if (dict.ContainsKey(s))
                Console.WriteLine(s + "=" + dict[s]);
            else
                Console.WriteLine("Not found");
            }
            catch {
                break;
            }
        }
    }
}

// n줄의 전화번호부와 *임의의 줄*의 검색이 주어졌을 때 결과 출력하기
// Dictionary 사용 연습
// 검색 수는 정해져있지 않음에 주의 - 1번 테케는 100000개의 입력을 받지만 쿼리는 50000개임