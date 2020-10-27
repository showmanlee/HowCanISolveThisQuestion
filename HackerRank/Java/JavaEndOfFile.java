// Java End-of-file
// https://www.hackerrank.com/challenges/java-end-of-file/problem

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i = 1;
        while(scanner.hasNext()){
            String p = scanner.nextLine();
            System.out.println(i + " " + p);
            i++;
        }
    }
}

// Java에서 입력 종료(EOF) 감지 = scanner.hasNext()