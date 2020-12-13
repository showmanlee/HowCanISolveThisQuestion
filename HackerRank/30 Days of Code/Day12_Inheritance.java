// Day 12: Inheritance
// https://www.hackerrank.com/challenges/30-inheritance/problem

import java.util.*;

class Person {
	protected String firstName;
	protected String lastName;
	protected int idNumber;
	
	// Constructor
	Person(String firstName, String lastName, int identification){
		this.firstName = firstName;
		this.lastName = lastName;
		this.idNumber = identification;
	}
	
	// Print person data
	public void printPerson(){
		 System.out.println(
				"Name: " + lastName + ", " + firstName 
			+ 	"\nID: " + idNumber); 
	}
	 
}

class Student extends Person{
	private int[] testScores;
    
    Student(String f, String l, int i, int[] s){
        super(f, l, i);
        this.testScores = s;
    }
    public char calculate(){
        int avg = 0;
        for (int i : testScores)
            avg += i;
        avg /= testScores.length;
        if (avg >= 90)
            return 'O';
        if (avg >= 80)
            return 'E';
        if (avg >= 70)
            return 'A';
        if (avg >= 55)
            return 'P';
        if (avg >= 40)
            return 'D';
        return 'T';  
    }
}

class Solution {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String firstName = scan.next();
		String lastName = scan.next();
		int id = scan.nextInt();
		int numScores = scan.nextInt();
		int[] testScores = new int[numScores];
		for(int i = 0; i < numScores; i++){
			testScores[i] = scan.nextInt();
		}
		scan.close();
		
		Student s = new Student(firstName, lastName, id, testScores);
		s.printPerson();
		System.out.println("Grade: " + s.calculate() );
	}
}

// 미리 만들어진 Person 클래스를 상속받아 scores 멤버 배열을 만들고, 해당 값의 평균으로 성적 출력하는 함수 만들기
// C#에서 파생 클래스 생성 및 생성자 조작