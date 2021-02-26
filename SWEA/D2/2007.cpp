// 2007. 패턴 마디의 길이
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5P1kNKAl8DFAUq

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
        for(int i = 1; i <= 10; i++){
            if (s.substr(0, i) == s.substr(i, i)){
                cout << '#' << test_case << ' ' << i << '\n';
                break;
            }
        }
	}
	return 0;
}

// 문자열 패턴의 마디 길이 구하기
// 민감해할 필요 없이 앞쪽 substr을 비교해보면 됨