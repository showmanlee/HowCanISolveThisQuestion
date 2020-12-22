// 심부름 가는 길
// https://www.acmicpc.net/problem/5554

#include <iostream>
using namespace std;

int main(void){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int p = a + b + c + d;
    cout << (p / 60) << '\n' << (p % 60) << '\n';
}

// 초를 분으로 변환하기