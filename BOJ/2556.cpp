// 별 찍기 - 14
// https://www.acmicpc.net/problem/2556

#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << "*";
        cout << endl;
    }
}

// 사실 정사각형 찍는 문제