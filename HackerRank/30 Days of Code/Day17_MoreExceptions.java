// Day 17: More Exceptions
// https://www.hackerrank.com/challenges/30-more-exceptions/problem

import java.util.*;
import java.io.*;

class Calculator{
    public int power(int n, int p) throws Exception{
        if (n < 0 || p < 0)
            throw new Exception("n and p should be non-negative");
        return (int)Math.pow((int)n, (int)p);
    }
}

class Solution{

    public static void main(String[] args) {
    
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
        
            int n = in.nextInt();
            int p = in.nextInt();
            Calculator myCalculator = new Calculator();
            try {
                int ans = myCalculator.power(n, p);
                System.out.println(ans);
            }
            catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
        in.close();
    }
}


// 예외 자체 생성 및 메시지 달기 - 주어진 코드에 예외 처리 코드가 있음에 주의
// 메서드에 throws Exception 등록시킨 후 throw new Exception("...")