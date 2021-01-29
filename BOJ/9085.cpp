// 더하기
// https://www.acmicpc.net/problem/9085

#include <iostream>
using namespace std;

int main(void){
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++){
        int n;
        cin >> n;
        int res = 0;
        for (int i = 0; i < n; i++){
            int p;
            cin >> p;
            res += p;
        }
        cout << res << '\n';
    }
}

// 주어진 수를 모두 더한 값은?
// for로 더하기