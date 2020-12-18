// Day 17: More Exceptions
// https://www.hackerrank.com/challenges/30-more-exceptions/problem

using System;

class Calculator{
    public int power(int n, int p){
        if (n < 0 || p < 0)
            throw new Exception("n and p should be non-negative");
        return (int)Math.Pow(n, p);
    }
}

class Solution{
    static void Main(String[] args){
        Calculator myCalculator=new  Calculator();
        int T=Int32.Parse(Console.ReadLine());
        while(T-->0){
            string[] num = Console.ReadLine().Split();
            int n = int.Parse(num[0]);
            int p = int.Parse(num[1]); 
            try{
                int ans=myCalculator.power(n,p);
                Console.WriteLine(ans);
            }
            catch(Exception e){
               Console.WriteLine(e.Message);

            }
        }       
    }
}

// 예외 자체 생성 및 메시지 달기 - 주어진 코드에 예외 처리 코드가 있음에 주의
// throw new Exception("...")