// 2070. 큰 놈, 작은 놈, 같은 놈
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QQ6qqA40DFAUq

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
        cout << '#' << test_case << ' ';
        if (a > b)
            cout << '>';
        else if (a < b)
            cout << '<';
        else
            cout << '=';
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

// 단순 비교