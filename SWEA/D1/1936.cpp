// 1936. 1대1 가위바위보
// https://swexpertacademy.com/main/code/problem/problemSubmitHistory.do?contestProbId=AV5PjKXKALcDFAUq

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int a, b;
    cin >> a >> b;
    cout << (a % 3 == (b + 1) % 3 ? 'A' : 'B') << '\n';
	return 0;
}

// 가위는 1, 바위는 2, 보는 3일 때 A, B의 승패 결정하기
// 두 수의 차이를 체크, 나머지 연산을 적용하면 한 줄로 처리 가능