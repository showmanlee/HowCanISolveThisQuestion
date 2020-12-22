// Day 21: Generics
// https://www.hackerrank.com/challenges/30-generics/problem

using System;

class Printer
{
    
    public static void PrintArray<T>(T[] arr){
        foreach(var t in arr)
            Console.WriteLine(t);
    }


    static void Main(string[] args)
	{
		int n = Convert.ToInt32(Console.ReadLine());
		int[] intArray = new int[n];
		for (int i = 0; i < n; i++)
		{
			intArray[i] = Convert.ToInt32(Console.ReadLine());
		}
		
		n = Convert.ToInt32(Console.ReadLine());
		string[] stringArray = new string[n];
		for (int i = 0; i < n; i++)
		{
			stringArray[i] = Console.ReadLine();
		}
		
		PrintArray<Int32>(intArray);
		PrintArray<String>(stringArray);
	}
}

// 어떤 타입이든 받을 수 있는 제네릭 함수 만들기
// 함수 이름 앞에 <T> 붙이기
// Python은 어차피 자료형을 명시받지 않으므로 제네릭 개념이 없음