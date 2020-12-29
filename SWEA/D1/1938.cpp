// 1938. 아주 간단한 계산기
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PjsYKAMIDFAUq

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int a, b;
    cin >> a >> b;
    cout << (a+b) << '\n' << (a-b) << '\n' << (a*b) << '\n' << (a/b) << '\n';
	return 0;
}

// 두 자연수를 더하고 빼고 곱하고 나눈 결과 출력