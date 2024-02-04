// Tautogram
// https://www.acmicpc.net/problem/5698

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    while (true) {
        getline(cin, s);
        if (s == "*") {
            break;
        }
        stringstream ss(s);
        char c = ' ';
        bool res = true;
        string t;
        while (ss >> t) {
            if (c == ' ') {
                c = toupper(t[0]);
            } else {
                if (toupper(t[0]) != c) {
                    res = false;
                }
            }
        }
        cout << (res ? "Y" : "N") << '\n';
    }
}

// 주어진 알파벳 문자열 내 단어들의 시작 문자가 모두 동일한지 확인하기

// stringstream으로 파싱 후 각 단어별로 모두 동일한지 확인하기