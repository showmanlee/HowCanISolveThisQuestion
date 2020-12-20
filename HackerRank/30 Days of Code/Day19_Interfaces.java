// Day 19. Interfaces
// https://www.hackerrank.com/challenges/30-interfaces/problem

import java.io.*;
import java.util.*;

interface AdvancedArithmetic{
   int divisorSum(int n);
}
class Calculator implements AdvancedArithmetic {
    @Override
    public int divisorSum(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++)
            if (n % i == 0)
                res += i;
        return res;
    }
}

class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.close();
        
      	AdvancedArithmetic myCalculator = new Calculator(); 
        int sum = myCalculator.divisorSum(n);
        System.out.println("I implemented: " + myCalculator.getClass().getInterfaces()[0].getName() );
        System.out.println(sum);
    }
}

// 인터페이스 상속하여 실체화하기
// interface로 인터페이스 선언, 이를 implements하는 클래스는 인터페이스의 메서드를 모두 @Override해야 함
