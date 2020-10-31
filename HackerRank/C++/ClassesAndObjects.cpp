// Classes and Objects
// https://www.hackerrank.com/challenges/classes-objects/problem

class Student{
private:
    int scores[5];
public:
    void input(){
        for (int i = 0; i < 5; i++)
            cin >> scores[i];
    }
    int calculateTotalScore(){
        int sum = 0;
        for (int i = 0; i < 5; i++)
            sum += scores[i];
        return sum;
    }
};

// 클래스는 객체를 생성하기 위한 빵틀같은 것
// 하나의 클래스를 활용해 여러 개의 객체를 만들 수도 있고, 배열을 만들 수도 있음
// 물론 멤버 변수로 배열을 갖는 것도 가능