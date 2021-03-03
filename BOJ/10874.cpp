// 이교수님의 시험
// https://www.acmicpc.net/problem/10874

#include <iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int res = 0;
        for (int j = 0; j < 10; j++){
            int p;
            cin >> p;
            if (p == j % 5 + 1)
                res++;
        }
        if (res == 10)
            cout << i << '\n';
    }
}

// 10문제 5지선다 시험의 정답이 1234512345일 때, 만점자는?
// 인덱스에 따라 나머지 연산