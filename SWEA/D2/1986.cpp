// 1986. 지그재그 숫자
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PxmBqAe8DFAUq

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
        int res = 0;
        for (int i = 1; i <= n; i++){
            if (i % 2 == 1)
                res += i;
            else
                res -= i;
        }
        cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0;
}

// 홀수면 더하고 짝수면 빼기
// 사실 더 간단한 조건문으로 처리 가능