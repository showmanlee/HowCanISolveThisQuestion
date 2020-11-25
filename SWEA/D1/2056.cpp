// 2056. 연월일 달력
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QLkdKAz4DFAUq

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    int date[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string s;
        cin >> s;
        cout << '#' << test_case << ' ';
        if ((stoi(s.substr(4, 2)) >= 1 && stoi(s.substr(4, 2)) <= 12) && (stoi(s.substr(6, 2)) >= 1 && stoi(s.substr(6, 2)) <= date[stoi(s.substr(4, 2))]))
            cout << s.substr(0, 4) << '/' << s.substr(4, 2) << '/' << s.substr(6, 2) << '\n';
        else
            cout << -1 << '\n';
	}
	return 0;
}

// 연도 제한은 없음 - 그냥 날짜 받아서 유효하면 변환하면 됨