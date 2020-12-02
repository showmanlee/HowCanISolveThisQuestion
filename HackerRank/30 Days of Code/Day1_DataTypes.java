// Day 1: Data Types
// https://www.hackerrank.com/challenges/30-data-types/problem

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
	
    public static void main(String[] args) {
        int i = 4;
        double d = 4.0;
        String s = "HackerRank ";
		
        Scanner scan = new Scanner(System.in);

        int j = scan.nextInt();
        double e = scan.nextDouble();
        scan.nextLine();
        String t = scan.nextLine();
        
        System.out.println(i + j);
        System.out.println(d + e);
        System.out.println(s + t);

        scan.close();
    }
}

// 정수형, 실수형, 문자열을 입력받고 미리 만들어진 변수와 더하기/붙이기
// Scanner.nextLine() 사용 전에 nextLine()을 쓰지 않았다면 빈 nextLine()으로 플러싱
// 여기는 실수형 결과에 자동으로 .0을 붙여줌