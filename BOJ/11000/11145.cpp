// Is it a Number?
// https://www.acmicpc.net/problem/11145

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        while (!s.empty()) {
            if (s[0] == ' ') {
                s = s.substr(1);
            } else if (s.back() == ' ') {
                s.pop_back();
            } else {
                break;
            }
        }
        bool res = (s.empty() ? false : true);
        for (char c : s) {
            if (!isdigit(c)) {
                res = false;
                break;
            }
        }
        if (res) {
            while (s.length() > 1) {
                if (s[0] == '0') {
                    s = s.substr(1);
                } else {
                    break;
                }
            }
        }
        if (res) {
            cout << s << '\n';
        } else {
            cout << "invalid input\n";
        }
    }
}

// 주어진 문자열에 기호 및 중간 공백 없는 정수만 있는지 확인하고, 실제 정수로 출력하기

// 앞뒤의 공백, 그리고 0을 지우면 되는데, stoi로 범위 초과할 수 있으니 문자열로 관리해준다