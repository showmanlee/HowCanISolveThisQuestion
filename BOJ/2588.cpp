// 곱셈
// https://www.acmicpc.net/problem/2588

#include <iostream>
using namespace std;

int main(void){
    int a, b;
    cin >> a >> b;
    cout << a * (b % 10) << endl << a * (b / 10 % 10) << endl << a * (b / 100) << endl << a * b << endl;
}