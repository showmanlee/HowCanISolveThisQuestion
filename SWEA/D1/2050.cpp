// 2050. 알파벳을 숫자로 변환
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QLGxKAzQDFAUq

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    string s;
    cin >> s;
    for (char c : s)
        cout << (int)(c - 'A' + 1) << ' ';
    cout << '\n';
	return 0;
}

// 알파벳은 모두 대문자, 시작이 1임에 주의