// 이상한 기호
// https://www.acmicpc.net/problem/15964

#include <iostream>
using namespace std;

int main(void){
    long long a, b;
    cin >> a >> b;
    cout << ((a + b) * (a - b)) << '\n';
}

// 값으로만 따지면 int로 커버가 안 된다는 것만 알면 됨