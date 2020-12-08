// Day 7: Arrays
// https://www.hackerrank.com/challenges/30-arrays/problem

import java.io.*;
import java.util.*;

public class Solution {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }
        
        for (int i = n - 1; i >= 0; i--)
            System.out.print(arr[i] + " ");
        System.out.println();
        scanner.close();
    }
}



// 오늘은 배열
// 배열 숫자 받아서 거꾸로 출력하기