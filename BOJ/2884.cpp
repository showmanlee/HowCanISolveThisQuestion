// 알람 시계
// https://www.acmicpc.net/problem/2884

#include <iostream>
using namespace std;

int main(void){
    int h, m;
    cin >> h >> m;
    m -= 45;
    if (m < 0){
        m += 60;
        h--;
        if (h < 0)
            h += 24;
    }
    cout << h << " " << m << endl;
}