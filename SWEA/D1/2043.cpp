// 2043. 서랍의 비밀번호
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QJ_8KAx8DFAUq

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int a, b;
    cin >> a >> b;
    cout << (a - b + 1) << '\n';
    return 0;
}

// b부터 하나씩 올려 a까지 도달할 때 시도하는 횟수
// 계산