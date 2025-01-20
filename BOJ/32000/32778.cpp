// 가희와 부역명
// https://www.acmicpc.net/problem/32778

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);
    int a = -1, b = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            a = i;
        } else if (s[i] == ')') {
            b = i;
        }
    }
    if (a == -1) {
        cout << s << '\n' << '-' << '\n';
    } else {
        string sa = s.substr(0, a - 1);
        string ss = s.substr(a + 1, b - a - 1);
        cout << sa << '\n' << ss << '\n';
    }
}

// 역명 (부역명) 꼴로 들어오는 문자열에서 역명과 부역명 출력하기