// Day 7: Arrays
// https://www.hackerrank.com/challenges/30-arrays/problem

using System;

class Solution {
    static void Main(string[] args) {
        int n = Convert.ToInt32(Console.ReadLine());

        int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));
        
        for (int i = n - 1; i >= 0; i--)
            Console.Write(arr[i] + " ");
        Console.WriteLine();
    }
}


// 오늘은 배열
// 배열 숫자 받아서 거꾸로 출력하기