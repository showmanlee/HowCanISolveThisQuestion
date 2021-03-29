// 특별한 날
// https://www.acmicpc.net/problem/10768

#include <iostream>
#include <string>
using namespace std;

int main(void){
    int m, d;
    cin >> m >> d;
    if (m == 2){
        if (d == 18)
            cout << "Special\n";
        else if (d < 18)
            cout << "Before\n";
        else
            cout << "After\n";
    }
    else if (m == 1)
        cout << "Before\n";
    else
        cout << "After\n";
}

// 주어진 날짜가 2월 18일 이전인가, 이후인가, 또는 2월 18일인가?
// 달 먼저 체크하고, 그 다음 날 체크하기