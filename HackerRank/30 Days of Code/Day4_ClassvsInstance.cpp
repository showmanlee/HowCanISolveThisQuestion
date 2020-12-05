// Day 4: Class vs. Instance
// https://www.hackerrank.com/challenges/30-class-vs-instance/problem

using namespace std;
#include <iostream>

class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
};

Person::Person(int initialAge){
    age = initialAge;
    if (age < 0){
        cout << "Age is not valid, setting age to 0.\n";
        age = 0;
    }
}

void Person::amIOld(){
    if (age < 13)
        cout << "You are young.\n";
    else if (age >= 13 && age < 18)
        cout << "You are a teenager.\n";
    else
        cout << "You are old.\n";
}

void Person::yearPasses(){
    age++;
}

int main(){
    int t;
    int age;
    cin >> t;
    for(int i=0; i < t; i++) {
    	cin >> age;
        Person p(age);
        p.amIOld();
        for(int j=0; j < 3; j++) {
        	p.yearPasses(); 
        }
        p.amIOld();
      
		cout << '\n';
    }

    return 0;
}

// 클래스 만들기
// C++에서 클래스 만들고, 클래스 바깥에서 함수 정의하고, 객체 만들기