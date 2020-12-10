// Day 9: Recursion 3
// https://www.hackerrank.com/challenges/30-recursion/problem

import java.io.*;
import java.util.*;

public class Solution {

    // Complete the factorial function below.
    static int factorial(int n) {
        if (n <= 1)
            return 1;
        return n * factorial(n - 1);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int result = factorial(n);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}



// 재귀 함수로 팩토리얼 짜기
// factorial(n) = n * factorial(n - 1)
// (factorial(1) = 1)