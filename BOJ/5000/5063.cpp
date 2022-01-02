// TGN
// https://www.acmicpc.net/problem/5063

#include <iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int r, e, c;
        cin >> r >> e >> c;
        if (r < e - c)
            cout << "advertise\n";
        else if (r == e - c)
            cout << "does not matter\n";
        else
            cout << "do not advertise\n";
    }
}

// 광고하지 않을 때 수익 r, 광고했을 때 수익 e, 광고비 c가 주어질 때, 광고로 수익을 낼 수 있는지, 상관없는지, 수익을 낼 수 없는지 판단하기
// r vs e - c