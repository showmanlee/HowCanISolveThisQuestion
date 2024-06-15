// Adding Commas
// https://www.acmicpc.net/problem/5949

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    string res;
    for (int i = 0; i < s.length(); i++) {
        res = s[s.length() - 1 - i] + res;
        if (i % 3 == 2 && i != s.length() - 1) {
            res = ',' + res;
        }
    }
    cout << res << '\n';
}

// 주어진 정수에 자릿수 콤마 붙이기