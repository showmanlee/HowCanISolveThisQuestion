// ピアノコンクール (Piano Competition)
// https://www.acmicpc.net/problem/22016

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, k;
    string s;
    cin >> n >> k >> s;
    k--;
    for (int i = k; i < n; i++) {
        if (isupper(s[i])) {
            s[i] = tolower(s[i]);
        } else if (islower(s[i])) {
            s[i] = toupper(s[i]);
        }
    }
    cout << s << '\n';
}

// 주어진 문자열에서 특정 글자 이후 대소문자 바꾸기