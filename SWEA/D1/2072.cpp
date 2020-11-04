// 2072. 홀수만 더하기
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QSEhaA5sDFAUq 

#include<iostream>
 
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int res = 0;
        for (int i = 0; i < 10; i++){
            int a;
            cin >> a;
            if (a % 2 == 1)
                res += a;
        }
        cout << '#' << test_case << ' ' << res << '\n';
    }
    return 0;
}

// 새로운 사이트에 진출!
// 삼성이 소프트웨어 육성에 열심이란 건 유명하지요