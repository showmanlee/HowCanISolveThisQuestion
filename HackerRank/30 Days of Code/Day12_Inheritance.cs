// Day 12: Inheritance
// https://www.hackerrank.com/challenges/30-inheritance/problem

using System;
using System.Linq;

class Person{
	protected string firstName;
	protected string lastName;
	protected int id;
	
	public Person(){}
	public Person(string firstName, string lastName, int identification){
			this.firstName = firstName;
			this.lastName = lastName;
			this.id = identification;
	}
	public void printPerson(){
		Console.WriteLine("Name: " + lastName + ", " + firstName + "\nID: " + id); 
	}
}

class Student : Person{
    private int[] testScores;  
    public Student(string f, string l, int i, int[] s) : base(f, l, i){
        testScores = s;
    }
    public char Calculate(){
        int avg = 0;
        foreach (int i in testScores)
            avg += i;
        avg /= testScores.Length;
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
	static void Main() {
		string[] inputs = Console.ReadLine().Split();
		string firstName = inputs[0];
	  	string lastName = inputs[1];
		int id = Convert.ToInt32(inputs[2]);
		int numScores = Convert.ToInt32(Console.ReadLine());
		inputs = Console.ReadLine().Split();
	  	int[] scores = new int[numScores];
		for(int i = 0; i < numScores; i++){
			scores[i]= Convert.ToInt32(inputs[i]);
		} 
	  	
		Student s = new Student(firstName, lastName, id, scores);
		s.printPerson();
		Console.WriteLine("Grade: " + s.Calculate() + "\n");
	}
}

// 미리 만들어진 Person 클래스를 상속받아 scores 멤버 배열을 만들고, 해당 값의 평균으로 성적 출력하는 함수 만들기
// C#에서 파생 클래스 생성 및 생성자 조작