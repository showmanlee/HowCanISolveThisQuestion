// 학술대회 참가신청
// https://www.acmicpc.net/problem/32969

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);
    string v[7] = {"social", "history", "language", "literacy", "bigdata", "public", "society"};
    for (char& c : s) {
        if (isupper(c)) {
            c = tolower(c);
        }    
    }
    for (int t = 0; t < 7; t++) {
        bool pass = false;
        if (s.length() < v[t].length()) {
            continue;
        }
        for (int i = 0; i <= s.length() - v[t].length(); i++) {
            if (s.substr(i, v[t].length()) == v[t]) {
                pass = true;
                break;
            }
        }
        if (pass) {
            if (t <= 3) {
                cout << "digital humanities";
            } else {
                cout << "public bigdata";
            }
            cout << '\n';
            break;
        }
    }
}

// 주어진 대소문자 문자열에서 특정 단어가 나오면 분류가 결정될 때, 분류 구하기