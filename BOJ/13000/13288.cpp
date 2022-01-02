// A New Alphabet
// https://www.acmicpc.net/problem/13288

#include <iostream>
#include <string>
using namespace std;

string na[26] = {"@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|", "\\/", "\\/\\/", "}{", "`/", "2"};

int main(void) {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            cout << (na[s[i] - 'A']);
        else if (s[i] >= 'a' && s[i] <= 'z')
            cout << (na[s[i] - 'a']);
        else
            cout << s[i];
    }
    cout << '\n';
}

// 특정 알파벳을 특정 문자열로 대치하기
// 대문자/소문자 모두 들어올 수 있음, 그리고 이스케이프 시퀀스 처리에 주의