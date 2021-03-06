// 10부제
// https://www.acmicpc.net/problem/10797

#include <iostream>
using namespace std;

int main(void){
    int k;
    cin >> k;
    int res = 0;
    for (int i = 0; i < 5; i++){
        int p;
        cin >> p;
        if (p == k)
            res++;
    }
    cout << res << '\n';
}

// 오늘 날짜의 뒷자리와 그날 지나간 차 5대의 번호 뒷자리가 주어질 때, 10부제를 위반한 차량 수는?