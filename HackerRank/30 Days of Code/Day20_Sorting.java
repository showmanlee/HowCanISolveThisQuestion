// Day 20: Sorting
// https://www.hackerrank.com/challenges/30-sorting/problem

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        for(int a_i=0; a_i < n; a_i++){
            a[a_i] = in.nextInt();
        }
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
        System.out.printf("Array is sorted in %d swaps.\n", swaped);
        System.out.printf("First Element: %d\n", a[0]);
        System.out.printf("Last Element: %d\n", a[n-1]);
    }
}

// 버블 정렬 구현하고 교체 횟수 구하기
