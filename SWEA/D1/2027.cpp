// 2027. 대각선 출력하기
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QFuZ6As0DFAUq

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++)
            cout << (i == j ? '#' : '+');
        cout << '\n';
    }
	return 0;
}

/*
#++++
+#+++
++#++
+++#+
++++#

이거 출력하기
*/