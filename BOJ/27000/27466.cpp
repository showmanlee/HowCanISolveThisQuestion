// 그래서 대회 이름 뭐로 하죠
// https://www.acmicpc.net/problem/27466

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    string s;
    cin >> n >> m >> s;
    string res;
    for (int i = n - 1; i >= 0; i--) {
        if (res.length() == 0) {
            if (s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U') {
                res += s[i];
            }
        } else if (res.length() < 3) {
            if (s[i] == 'A') {
                res += s[i];
            }
        } else if (res.length() < m) {
            res += s[i];
        } else {
            break;
        }
    }
    if (res.length() == m) {
        reverse(res.begin(), res.end());
        cout << "YES\n" << res << '\n';
    } else {
        cout << "NO\n";
    }
}

// 길이 n의 대문자 문자열 s의 문자를 지워서 길이 m의 ...AA(자음) 꼴의 문자열을 만들 수 있는지 확인하기

// 뒤에서부터 순회하며 자음 -> A -> A -> (m - 3개의 문자)가 확보될 수 있는지 확인하고 문자열을 만든다