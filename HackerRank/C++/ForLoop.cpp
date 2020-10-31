// For Loop
// https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++){
        if (i == 1)
            cout << "one" << endl;
        else if (i == 2)
            cout << "two" << endl;
        else if (i == 3)
            cout << "three" << endl;
        else if (i == 4)
            cout << "four" << endl;
        else if (i == 5)
            cout << "five" << endl;
        else if (i == 6)
            cout << "six" << endl;
        else if (i == 7)
            cout << "seven" << endl;
        else if (i == 8)
            cout << "eight" << endl;
        else if (i == 9)
            cout << "nine" << endl;   
        else if (i % 2 == 0)
            cout << "even" << endl;
        else
            cout << "odd" << endl;
    }
    return 0;
}

// 언제나 쓰는 for문
// *초기화식* -> 조건식 -> 문장 -> 증감식 -> 조건식 -> 문장 -> 증감식.. 순임에 주의
// (최초 1회는 증감을 하지 않는다는 것, 이거 무의식적으로 쓰다가 까먹을 수도 있음)