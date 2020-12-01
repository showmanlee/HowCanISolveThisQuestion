// Day 0: Hello, World.
// https://www.hackerrank.com/challenges/30-hello-world/problem

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class Solution {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in); 
		String inputString = scan.nextLine(); 
		scan.close(); 
		System.out.println("Hello, World.");
        
        System.out.println(inputString);
	}
}

// 2020년을 마무리하는 대규모(?) 프로젝트 - 30 Days of Code 클리어
// 이번에는 C++뿐만 아니라 Java, Python, C#으로도 동시에 풀어봅니다
// 오늘은 입력 문자열을 받아두었을 때, 이를 출력하기