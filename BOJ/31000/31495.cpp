// 그게 무슨 코드니..
// https://www.acmicpc.net/problem/31495

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);
    int res = 0;
    if (s[0] == '\"' && s[s.length() - 1] == '\"' && s.length() > 2) {
        cout << s.substr(1, s.length() - 2) << '\n';
    } else {
        cout << "CE\n";
    }
}

// 주어진 문자열 양 끝에 큰따옴표가 있는지 판정하기

// 양끝의 문자를 보고 확인해줍시다 - 앞뒤로 공백이 없음이 보장되었으므로