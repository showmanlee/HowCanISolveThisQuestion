// Day 19. Interfaces
// https://www.hackerrank.com/challenges/30-interfaces/problem

using System;
public interface AdvancedArithmetic{
    int divisorSum(int n);
}

public class Calculator : AdvancedArithmetic
{
    public int divisorSum(int n)
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
            if (n % i == 0)
                res += i;
        return res;
    }
}

class Solution{
    static void Main(string[] args){
        int n = Int32.Parse(Console.ReadLine());
      	AdvancedArithmetic myCalculator = new Calculator();
        int sum = myCalculator.divisorSum(n);
        Console.WriteLine("I implemented: AdvancedArithmetic\n" + sum); 
    }
}

// 인터페이스 상속하여 실체화하기
// interface로 인터페이스 선언, 이를 상속하는 클래스는 인터페이스의 메서드를 모두 오버라이딩해야 함
