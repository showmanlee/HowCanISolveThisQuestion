// XORChic
// https://www.acmicpc.net/problem/17285

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    char key = s[0] ^ 'C';
    for (char& c : s) {
        c = c ^ key;
    }
    cout << s << '\n';
}

// 어떤 키값으로 xor 처리된 문자열의 첫 8글자가 "CHICKENS"일 때, xor 처리된 문자열 복구하기

// 첫 글자와 'C'를 xor하면 키가나온다