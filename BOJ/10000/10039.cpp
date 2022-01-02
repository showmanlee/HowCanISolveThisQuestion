// 평균 점수
// https://www.acmicpc.net/problem/10039

#include <iostream>
using namespace std;

int main(void){
    int sum = 0;
    for (int i = 0; i < 5; i++){
        int n;
        cin >> n;
        if (n < 40)
            n = 40;
        sum += n;
    }
    cout << (sum / 5) << endl;
}

// 5명의 점수를 받아 평균값을 내보자
// 40점 미만일 경우 40점이 됨에 주의