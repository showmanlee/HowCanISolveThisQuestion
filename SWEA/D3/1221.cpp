// 1221. [S/W 문제해결 기본] 5일차 - GNS
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14jJh6ACYCFAYD

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    string shift[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string tc;
        int len;
        vector<int> ord;
        cin >> tc >> len;
        for (int i = 0; i < len; i++){
            string s;
            cin >> s;
            if (s == "ZRO")
                ord.push_back(0);
            else if (s == "ONE")
                ord.push_back(1);
            else if (s == "TWO")
                ord.push_back(2);
            else if (s == "THR")
                ord.push_back(3);
            else if (s == "FOR")
                ord.push_back(4);
            else if (s == "FIV")
                ord.push_back(5);
            else if (s == "SIX")
                ord.push_back(6);
            else if (s == "SVN")
                ord.push_back(7);
            else if (s == "EGT")
                ord.push_back(8);
            else if (s == "NIN")
                ord.push_back(9);
        }
        sort(ord.begin(), ord.end());
        cout << tc << '\n';
        for (int i = 0; i < len; i++)
            cout << shift[ord[i]] << ' ';
        cout << '\n';
	}
	return 0;
}

// 숫자를 문자열로 받아 정렬해서 출력하기
// 입력받은 문자열을 숫자로 바꾸면 되려나