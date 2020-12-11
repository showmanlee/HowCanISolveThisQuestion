// Day 10: Binary Numbers
// https://www.hackerrank.com/challenges/30-binary-numbers/problem

import java.io.*;
import java.util.*;

public class Solution {
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
        
        int max = 0, count = 0;
        while(n > 0){
            if (n % 2 == 1){
                count++;
                if (max < count)
                    max = count;
            }
            else
                count = 0;
            n /= 2;
        }
        System.out.println(max);
        
        scanner.close();
    }
}

// 10진수를 2진수로 변환하고, 연속해서 나오는 1의 최대 개수 구하기