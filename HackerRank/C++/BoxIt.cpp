// Box It!
// https://www.hackerrank.com/challenges/box-it/problem

class Box {
private:
    int l, b, h;
public:
    Box() {
        l = b = h = 0;
    }
    Box(int length, int breadth, int height) {
        l = length;
        b = breadth;
        h = height;
    }
    Box(Box& B) {
        l = B.l;
        b = B.b;
        h = B.h;
    }
    int getLength() {
        return l;
    }
    int getBreadth() {
        return b;
    }
    int getHeight() {
        return h;
    }
    long long CalculateVolume() {
        return (long long)l * b * h;
    }
    bool operator<(Box& B) {
        if (l != B.l)
            return l < B.l;
        else if (b != B.b)
            return b < B.b;
        else
            return h < B.h;
    }
    friend ostream& operator<<(ostream& out, Box& B)
    {
        out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
        return out;
    }
};

// 생성자가 있는 클래스
// Box(Box& B) 꼴로 되어 있는 생성자는 복사 생성자.
// 복사 생성자는 선언과 동시에 초기화될 때(대입 연산), 매개변수로 전달될 때(값으로 전달될 때만), 반환값으로 객체가 반환될 때 사용
// 컴파일러에서 기본으로 복사 생성자를 만들어주긴 하나, 얕은 복사 기반이라 깊은 복사가 필요할 때(멤버 변수 중 포인터가 있다거나)는 직접 만들어주어야 한다
// cout에서 <<를 통해 객체를 프린트하고 싶다면 위와 같은 방식으로 만들어주어야 한다
// 한 클래스 안에 friend 키워드로 선언된 클래스/함수는 거기에 적힌 클래스에서 자유롭게 private 멤버에 접근할 수 있는 권한을 준다