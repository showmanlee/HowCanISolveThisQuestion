// 크냐?
// https://www.acmicpc.net/problem/4101

#include <iostream>
using namespace std;

int main(void){
    while(true){
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        cout << (a > b ? "Yes" : "No") << '\n';
    }
}

// 왼쪽 수가 오른쪽 수보다 큰가?