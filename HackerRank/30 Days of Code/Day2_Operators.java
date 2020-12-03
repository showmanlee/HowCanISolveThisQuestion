// Day 2: Operators
// https://www.hackerrank.com/challenges/30-operators/problem

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the solve function below.
    static void solve(double meal_cost, int tip_percent, int tax_percent) {
        double res = meal_cost + (tip_percent / 100.0 * meal_cost) + (tax_percent / 100.0 * meal_cost);
        System.out.println(Math.round(res));
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        double meal_cost = scanner.nextDouble();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int tip_percent = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int tax_percent = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        solve(meal_cost, tip_percent, tax_percent);

        scanner.close();
    }
}

// 고기 가격, 팁, 세금 비율이 주어졌을 때 최종 구매가를 반올림하여 출력하기
// 이 언어에서 round 함수를 쓰는 법을 아나요? - Math.round 사용