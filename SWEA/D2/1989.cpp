// 1989. 초심자의 회문 검사
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PyTLqAf4DFAUq

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string s;
        cin >> s;
        int i1 = s.length() / 2 - (s.length() % 2 == 0 ? 1 : 0);
        int i2 = s.length() / 2;
        int res = 1;
        for (int i = 0; i <= s.length() / 2; i++){
            if (s[i1 - i] != s[i2 + i])
                res = 0;
        }
        cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0;
}

// 길이 10 이하의 문자열이 회문인지 판별하기
// 그정도는 for 문으로 처리 가능