// Day 16: Exceptions - String to Integer
// https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String S = in.next();
        try{
            System.out.println(Integer.parseInt(S));
        }
        catch(Exception e){
            System.out.println("Bad String");
        }
    }
}

// 예외 처리로 숫자만 있는 문자열 구분하기
// try... catch(Exception e)