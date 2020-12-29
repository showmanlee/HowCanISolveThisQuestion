// 2019. 더블더블
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QDEX6AqwDFAUq

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int n, res = 1;
    cin >> n;
    for (int i = 0; i <= n; i++){
        cout << res << ' ';
        res *= 2;
    }
    cout << '\n';
	return 0;
}

// 1부터 2^n까지 2를 곱한 수열 출력
// 1부터 출력해야 함에 유의