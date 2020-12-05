// Day 4: Class vs. Instance
// https://www.hackerrank.com/challenges/30-class-vs-instance/problem

import java.io.*;
import java.util.*;

public class Person {
    private int age;	
  
	public Person(int initialAge) {
  		age = initialAge;
        if (age < 0){
            System.out.println("Age is not valid, setting age to 0.");
            age = 0;
        }
	}

	public void amIOld() {
        if (age < 13)
            System.out.println("You are young.");
        else if (age >= 13 && age < 18)
            System.out.println("You are a teenager.");
        else
            System.out.println("You are old.");
	}

	public void yearPasses() {
  		age++;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			int age = sc.nextInt();
			Person p = new Person(age);
			p.amIOld();
			for (int j = 0; j < 3; j++) {
				p.yearPasses();
			}
			p.amIOld();
			System.out.println();
        }
		sc.close();
    }
}

// 클래스 만들기
// Java에서 클래스 만들고, 함수 정의하고, 객체 만들어서 활용하기
// Java에서 클래스 생성에 별도의 파일이 필요하므로 여기에 main까지 넣기