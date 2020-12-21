// Day 20: Sorting
// https://www.hackerrank.com/challenges/30-sorting/problem

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {

    static void Main(String[] args) {
        int n = Convert.ToInt32(Console.ReadLine());
        string[] a_temp = Console.ReadLine().Split(' ');
        int[] a = Array.ConvertAll(a_temp,Int32.Parse);
        int swaped = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n - 1; j++){
                if (a[j] > a[j+1]){
                    int temp = a[j+1];
                    a[j+1] = a[j];
                    a[j] = temp;
                    swaped++;
                }
            }
        }
        Console.WriteLine("Array is sorted in {0} swaps.", swaped);
        Console.WriteLine("First Element: {0}", a[0]);
        Console.WriteLine("Last Element: {0}", a[n-1]);
    }
}

// 버블 정렬 구현하고 교체 횟수 구하기
