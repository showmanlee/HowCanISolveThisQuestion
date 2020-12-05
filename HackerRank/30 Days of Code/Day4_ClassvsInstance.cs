// Day 4: Class vs. Instance
// https://www.hackerrank.com/challenges/30-class-vs-instance/problem

using System;
using System.Collections.Generic;
using System.IO;

class Person {
    public int age;     
	public Person(int initialAge) {
        age = initialAge;
        if (age < 0){
            Console.WriteLine("Age is not valid, setting age to 0.");
            age = 0;
        }
     }
     public void amIOld() {
         if (age < 13)
            Console.WriteLine("You are young.");
        else if (age >= 13 && age < 18)
            Console.WriteLine("You are a teenager.");
        else
            Console.WriteLine("You are old.");
     }

     public void yearPasses() {
        age++;
     }

static void Main(String[] args) {
        int T=int.Parse(Console.In.ReadLine());
        for (int i = 0; i < T; i++) {
            int age=int.Parse(Console.In.ReadLine());
            Person p=new Person(age);
             p.amIOld();
                for (int j = 0; j < 3; j++) {
                  p.yearPasses();
                }
                p.amIOld();
                Console.WriteLine();
        }
    }
}

// 클래스 만들기
// C++에서 클래스 만들고, 메서드 정의하고, 객체 만들기