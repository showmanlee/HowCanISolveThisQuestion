// Letter Count
// https://www.acmicpc.net/problem/15184

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);
    vector<int> cnt(26);
    for (char c : s) {
        if (isupper(c)) {
            cnt[c - 'A']++;
        } else if (islower(c)) {
            cnt[c - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        cout << (char)(i + 'A') << " | ";
        for (int j = 0; j < cnt[i]; j++) {
            cout << '*';
        }
        cout << '\n';
    }
}

// 주어진 영어 문자열에 나오는 알파벳 개수를 그래프로 출력하기