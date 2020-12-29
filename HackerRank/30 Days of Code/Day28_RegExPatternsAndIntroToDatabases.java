// Day 28: RegEx, Patterns, and Intro to Databases
// https://www.hackerrank.com/challenges/30-regex-patterns/problem

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int N = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
        List<String> res = new ArrayList<>();
        for (int NItr = 0; NItr < N; NItr++) {
            String[] firstNameEmailID = scanner.nextLine().split(" ");
            String firstName = firstNameEmailID[0];
            String emailID = firstNameEmailID[1];
            if (emailID.split("@")[1].equals("gmail.com"))
                res.add(firstName);
        }
        res.sort(null);
        for (String s : res)
            System.out.println(s);
        scanner.close();
    }
}


// 정규 표현식 또는 split을 통한 데이터 추출
// gmail.com 이메일을 가지고 있는 사람의 이름을 오름차순으로 표시