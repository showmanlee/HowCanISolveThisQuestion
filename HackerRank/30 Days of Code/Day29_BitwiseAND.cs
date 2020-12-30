// Day 29: Bitwise AND
// https://www.hackerrank.com/challenges/30-bitwise-and/problem

using System;

class Solution {

    static void Main(string[] args) {
        int t = Convert.ToInt32(Console.ReadLine());

        for (int tItr = 0; tItr < t; tItr++) {
            string[] nk = Console.ReadLine().Split(' ');

            int n = Convert.ToInt32(nk[0]);
            int k = Convert.ToInt32(nk[1]);
            
            int res = 0;
            for (int i = 1; i < n; i++){
                for (int j = i + 1; j <= n; j++)
                    if (res < (i & j) && (i & j) < k)
                        res = i & j;
            }
            Console.WriteLine(res);
        }
    }
}


// 1~n까지 수 사이에 AND 연산한 결과 중 k 미만의 가장 큰 값 출력하기
// 30 Days of Code 끝! 올 한 해 마무리 잘 하시길 바랍니다
// 이제 문풀에 집중합시다