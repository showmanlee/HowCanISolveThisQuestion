// 2025. N줄덧셈
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QFZtaAscDFAUq

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += i;
    cout << res << '\n';
	return 0;
}

// 1부터 n까지 더한 수 출력하기