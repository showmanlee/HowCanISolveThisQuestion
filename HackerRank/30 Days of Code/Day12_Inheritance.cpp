// Day 12: Inheritance
// https://www.hackerrank.com/challenges/30-inheritance/problem

#include <iostream>
#include <vector>

using namespace std;

class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        Student(string f, string l, int i, vector<int> s) : Person(f, l, i){
            testScores = s;
        }
        char calculate(){
            int avg = 0;
            for (int i : testScores)
                avg += i;
            avg /= testScores.size();
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
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}

// 미리 만들어진 Person 클래스를 상속받아 scores 멤버 배열을 만들고, 해당 값의 평균으로 성적 출력하는 함수 만들기
// C++에서 파생 클래스 생성 및 생성자 조작