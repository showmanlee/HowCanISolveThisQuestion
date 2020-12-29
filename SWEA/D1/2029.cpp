// 2029. 몫과 나머지 출력하기
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QGNvKAtEDFAUq

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int a, b;
        cin >> a >> b;
        cout << '#' << test_case << ' ' << (a / b) << ' ' << (a % b) << '\n';
	}
	return 0;
}

// 말 그대로 몫과 나머지 출력하기