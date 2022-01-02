// 뜨거운 붕어빵
// https://www.acmicpc.net/problem/11945

#include <iostream>
#include <string>
using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = m - 1; j >= 0; j--)
            cout << s[j];
        cout << '\n';
    }
}

// 거꾸로 출력하기