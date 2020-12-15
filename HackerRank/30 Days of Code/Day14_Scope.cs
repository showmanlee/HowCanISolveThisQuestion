// Day 14: Scope
// https://www.hackerrank.com/challenges/30-scope/problem

using System;
using System.Linq;

class Difference {
    private int[] elements;
    public int maximumDifference;

	public Difference(int[] a){
        elements = a;
        maximumDifference = 0;
    }
    
    public void computeDifference(){
        Array.Sort(elements);
        for (int i = 0; i < elements.Length - 1; i++)
            for (int j = i + 1; j < elements.Length; j++)
                if (maximumDifference < elements[j] - elements[i])
                    maximumDifference = elements[j] - elements[i];
    }

} // End of Difference Class

class Solution {
    static void Main(string[] args) {
        Convert.ToInt32(Console.ReadLine());
        
        int[] a = Console.ReadLine().Split(' ').Select(x=>Convert.ToInt32(x)).ToArray();
        
        Difference d = new Difference(a);
        
        d.computeDifference();
        
        Console.Write(d.maximumDifference);
    }
}

// 배열과 배열 내 수의 차의 최댓값을 계산하는 함수를 가진 클래스 사용하기