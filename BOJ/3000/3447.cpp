// 버그왕
// https://www.acmicpc.net/problem/3447

#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    while (getline(cin, s)) {
        while (s.find("BUG") != -1) {
            s = regex_replace(s, regex("BUG"), "");
        }
        cout << s << '\n';
    }
}

// 주어진 문자열에서 BUG 모두 지우기

// BUG를 지워서 BUG가 나오면 그것도 지워야 함
// 다행히 std에는 정규표현식 헤더가 있음, 그래서 그걸로 연속으로 지워주면 됨 - https://modoocode.com/303