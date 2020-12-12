// Day 11: 2D Arrays
// https://www.hackerrank.com/challenges/30-2d-arrays/problem

using System;
using System.IO;

class Solution {
    static void Main(string[] args) {
        int[][] arr = new int[6][];

        for (int i = 0; i < 6; i++) {
            arr[i] = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));
        }
        
        int max = -80;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
                if (max < sum)
                    max = sum;
            }
        }
        Console.WriteLine(max);
    }
}

// 6x6 배열에서 나오는 3x3 모래시계 모양의 합 중 최댓값 구하기
// 음수가 나올 수 있음에 주의