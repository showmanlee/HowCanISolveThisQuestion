// Day 25: Running Time and Complexity
// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem

import java.io.*;
import java.util.*;

public class Solution {
    public static boolean isPrime(int n){
        if (n == 1)
            return false;
        for (int i = 2; i <= Math.sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++){
            int n = sc.nextInt();
            if (isPrime(n))
                System.out.println("Prime");
            else
                System.out.println("Not prime");
        }
        sc.close();
    }
}

// 소수 알고리즘 짜는데, O(n^2)가 나오지 않게 하기
// sqrt(n)까지 계산해도 됨