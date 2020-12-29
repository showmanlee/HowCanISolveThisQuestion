// 2047. 신문 헤드라인
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QKsLaAy0DFAUq

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] += 'A' - 'a';
    }
    cout << s << '\n';
}

// 소문자를 모두 대문자로 바꾸기
// 입력에 대문자가 들어감에 주의