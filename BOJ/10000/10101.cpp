// 삼각형 외우기
// https://www.acmicpc.net/problem/10101

#include <iostream>
using namespace std;

int main(void){
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c != 180)
        cout << "Error\n";
    else{
        if (a == b && b == c)
            cout << "Equilateral\n";
        else if (a == b || b == c || c == a)
            cout << "Isosceles\n";
        else
            cout << "Scalene\n";
    }
}

// 삼각형 판정하기 - 정삼각형, 이등변삼각형, 그냥 삼각형, 에러