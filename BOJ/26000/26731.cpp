// Zagubiona litera
// https://www.acmicpc.net/problem/26731

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    vector<bool> v(26);
    for (char c : s) {
        v[c - 'A'] = true;
    }
    for (int i = 0; i < 26; i++) {
        if (!v[i]) {
            cout << (char)(i + 'A') << '\n';
        }
    }
}

// 알파벳 26자 중 25자가 주어질 때, 남은 1글자 출력하기