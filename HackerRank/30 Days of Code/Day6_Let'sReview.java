// Day 6: Let's Review
// https://www.hackerrank.com/challenges/30-review-loop/problem

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();
        for (int i = 0; i < n; i++){
            String s = scan.nextLine();
            for (int j = 0; j < s.length(); j += 2)
                System.out.print(s.charAt(j));
            System.out.print(" ");
            for (int j = 1; j < s.length(); j += 2)
                System.out.print(s.charAt(j));
            System.out.println();
        }
        scan.close();
    }
}

// 1주차(입출력, 조건문, 반복문) 복습
// 문자열을 입력받고 짝수 번째 글자와 홀수 번째 글짜 따로 출력하기