// Quicksum
// https://www.acmicpc.net/problem/4613

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    while (getline(cin, s)) {
        if (s == "#") {
            break;
        }
        int res = 0;
        int cnt = 0;
        for (char c : s) {
            cnt++;
            if (c != ' ') {
                res += cnt * (c - 'A' + 1);
            }
        }
        cout << res << '\n';
    }
}

// 대문자 문자열에서 문자의 위치와 알파벳 순서로 만든 코드 출력하기

// 문제 보고 문자열 돌려가며 맞춰주기