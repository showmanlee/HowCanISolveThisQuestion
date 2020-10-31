// Inheritance Introduction
// https://www.hackerrank.com/challenges/inheritance-introduction/problem

class Triangle{
    public:
    	void triangle(){
     		cout<<"I am a triangle\n";
    	}
};

class Isosceles : public Triangle{
    public:
    	void isosceles(){
    		cout<<"I am an isosceles triangle\n";
    	}
  		void description(){
            cout << "In an isosceles triangle two sides are equal\n";
        }
};

// 기본적인 상속은 이런 방식으로 합니다 - class 이름 : public 부모
// 저 public에 private나 protected를 넣으면 부모 멤버 중 private/protected보다 넓은 접근자를 가진 것들이 모두 private/protected로 바뀐다