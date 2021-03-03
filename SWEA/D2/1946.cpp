// 1946. 간단한 압축 풀기
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PmkDKAOMDFAUq

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
        int n;
        cin >> n;
        string s;
        for (int i = 0; i < n; i++){
            char c;
            int p;
            cin >> c >> p;
            for (int j = 0; j < p; j++)
                s += c;
        }
        cout << '#' << test_case;
        for (int i = 0; i < s.length(); i++){
            if (i % 10 == 0)
                cout << '\n';
            cout << s[i];
        }
        cout << '\n';
	}
	return 0;
}

// 한 줄에 10개의 문자로 구성된 여러 줄의 문서가 연속된 문자를 '문자 숫자'로 압축하는 알고리즘으로 압축되어 있을 때, 해당 문서 압축 해제하기
// 한 줄에 10개씩 출력해야 함에 주의