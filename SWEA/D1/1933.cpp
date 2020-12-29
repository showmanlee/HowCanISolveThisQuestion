// 1933. 간단한 N 의 약수
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PhcWaAKIDFAUq

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            cout << i << ' ';
    cout << '\n';
	return 0;
}

// n(~1000)의 약수 순서대로 출력하기