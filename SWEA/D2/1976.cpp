// 1976. 시간 덧셈
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PttaaAZIDFAUq

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int aa, ab, ba, bb;
        cin >> aa >> ab >> ba >> bb;
        int a = aa + ba, b = ab + bb;
        if (b >= 60){
            a++;
            b %= 60;
        }
        if (a > 12){
            a = a % 12;
            if (a == 0)
                a = 12;
        }
        cout << '#' << test_case << ' ' << a << ' ' << b << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

// 12시간제 시각 두개 더하기
// 시(1~12) 핸들링만 해주면 24시간제와 비슷함