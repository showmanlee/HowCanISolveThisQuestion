// Day 26: Nested Logic
// https://www.hackerrank.com/challenges/30-nested-logic/problem

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();
        int z = sc.nextInt();
        int res = 0;
        if (c > z)
            res = 10000;
        else if (b > y && c == z)
            res = 500 * (b - y);
        else if (a > x && b == y && c == z)
            res = 15 * (a - x);
        System.out.println(res);
        sc.close();
    }
}

// 주어진 문제 구현하기
// 복합 조건문 문제