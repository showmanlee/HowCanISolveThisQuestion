// 바코드 닉네임
// https://www.acmicpc.net/problem/32288

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char& c : s) {
        if (c == 'l') {
            c = 'L';
        } else if (c == 'I') {
            c = 'i';
        }
    }
    cout << s << '\n';
}

// l과 I로 구성된 문자열에서 