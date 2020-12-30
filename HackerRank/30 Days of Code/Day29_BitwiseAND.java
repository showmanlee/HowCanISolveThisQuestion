// Day 29: Bitwise AND
// https://www.hackerrank.com/challenges/30-bitwise-and/problem

import java.util.*;

public class Solution {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String[] nk = scanner.nextLine().split(" ");

            int n = Integer.parseInt(nk[0]);

            int k = Integer.parseInt(nk[1]);
            
            int res = 0;
            for (int i = 1; i < n; i++){
                for (int j = i + 1; j <= n; j++)
                    if (res < (i & j) && (i & j) < k)
                        res = i & j;
            }
            System.out.println(res);
        }

        scanner.close();
    }
}


// 1~n까지 수 사이에 AND 연산한 결과 중 k 미만의 가장 큰 값 출력하기
// 30 Days of Code 끝! 올 한 해 마무리 잘 하시길 바랍니다
// 이제 문풀에 집중합시다