// 변수명
// https://www.acmicpc.net/problem/16205

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> v;
    string t;
    if (n == 2) {
        for (char c : s) {
            if (c == '_') {
                v.push_back(t);
                t = "";
            } else {
                t += c;
            }
        }
        v.push_back(t);
    } else {
        string ss = s.substr(1);
        if (n == 3) {
            t += s[0] - 'A' + 'a';
        } else {
            t += s[0];
        }
        for (char c : ss) {
            if (c >= 'A' && c <= 'Z') {
                v.push_back(t);
                t = "";
                c = c - 'A' + 'a';
                t += c;
            } else {
                t += c;
            }
        }
        v.push_back(t);
    }
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            cout << v[i];
        } else {
            char cc = v[i][0] - 'a' + 'A';
            cout << cc << v[i].substr(1);
        }
    }
    cout << '\n';
    for (int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1) {
            cout << v[i];
        } else {
            cout << v[i] << '_';
        }
    }
    cout << '\n';
    for (int i = 0; i < v.size(); i++) {
        char cc = v[i][0] - 'a' + 'A';
        cout << cc << v[i].substr(1);
    }
    cout << '\n';
}

// 변수명이 camelCase, snake_case, PascalCase 중 하나로 주어질 때, 각각의 케이스로 변환한 결과 출력하기

// 어떤 케이스인지가 명시적으로 주어지기 때문에, 케이스에 맞춰 각 단어들을 정리해서 넣어준 뒤, 케이스에 맞게 변환해서 출력한다