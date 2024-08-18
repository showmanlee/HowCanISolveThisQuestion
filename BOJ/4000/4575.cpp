// Refrigerator Magnets
// https://www.acmicpc.net/problem/4575

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    while (true) {
        getline(cin, s);
        if (s == "END") {
            break;
        }
        vector<int> cnt(26);
        bool res = true;
        for (char c : s) {
            if (c != ' ') {
                cnt[c - 'A']++;
                if (cnt[c - 'A'] > 1) {
                    res = false;
                    break;
                }
            }
        }
        if (res) {
            cout << s << '\n';
        }
    }
}

// 주어진 대문자 문자열 중 각 알파벳이 1개 이하로 등장하는 문자열 출력하기