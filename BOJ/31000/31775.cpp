// 글로벌 포닉스
// https://www.acmicpc.net/problem/31775

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    bool l = false, k = false, p = false;
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        if (s[0] == 'l') {
            l = true;
        }
        if (s[0] == 'k') {
            k = true;
        } 
        if (s[0] == 'p') {
            p = true;
        }
    }
    cout << (l && k && p ? "GLOBAL" : "PONIX") << '\n';
}

// 주어진 소문자 문자열 3개가 각각 l, k, p로 시작하는지 판정하기