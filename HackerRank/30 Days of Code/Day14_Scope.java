// Day 14: Scope
// https://www.hackerrank.com/challenges/30-scope/problem

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


class Difference {
  	private int[] elements;
  	public int maximumDifference;

	public Difference(int[] a){
        elements = a;
        maximumDifference = 0;
    }
    
    public void computeDifference(){
        Arrays.sort(elements);
        for (int i = 0; i < elements.length - 1; i++)
            for (int j = i + 1; j < elements.length; j++)
                if (maximumDifference < elements[j] - elements[i])
                    maximumDifference = elements[j] - elements[i];
    }
} // End of Difference class

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();

        Difference difference = new Difference(a);

        difference.computeDifference();

        System.out.print(difference.maximumDifference);
    }
}

// 배열과 배열 내 수의 차의 최댓값을 계산하는 함수를 가진 클래스 사용하기