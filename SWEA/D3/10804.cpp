// 10804. 문자열의 거울상
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXTC0x16D8EDFASe

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
        cout << "#" << test_case << ' ';
        for (int i = s.length() - 1; i >= 0; i--){
            switch(s[i]){
                case 'b':
                    cout << 'd';
                    break;
                case 'd':
                    cout << 'b';
                    break;
                case 'p':
                    cout << 'q';
                    break;
                case 'q':
                    cout << 'p';
                    break;
            }
        }
        cout << '\n';
	}
	return 0;
}

// 어떤 문자열이 주어졌을 때, 그 문자열을 거울에 비치면 어떤 결과가 나올까?
// 문자열을 거꾸로 순회하면서, 글자(bdpq) 자체도 거꾸로 만들어야 함
// 확실히 switch-case 문은 차지하는 공간이 크다