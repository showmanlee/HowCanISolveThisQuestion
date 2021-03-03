// 1970. 쉬운 거스름돈
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PsIl6AXIDFAUq

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        cout << '#' << test_case << '\n';
        cout << (n / 50000) << ' ' ;
        n %= 50000;
        cout << (n / 10000) << ' ' ;
        n %= 10000;
        cout << (n / 5000) << ' ' ;
        n %= 5000;
        cout << (n / 1000) << ' ' ;
        n %= 1000;
        cout << (n / 500) << ' ' ;
        n %= 500;
        cout << (n / 100) << ' ' ;
        n %= 100;
        cout << (n / 50) << ' ' ;
        n %= 50;
        cout << (n / 10) << ' ' ;
        n %= 10;
        cout << '\n';
    }
	return 0;
}

// 50000원~10원까지 거슬러주기
// 점점 작은 돈으로 거슬러주면 ok