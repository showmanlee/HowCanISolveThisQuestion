// PlayStation이 아니에요
// https://www.acmicpc.net/problem/32132

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
    for (int i = 0; i < s.length() - 2; i++) {
        if (s.length() <= 2) {
            break;
        }
        string ss = s.substr(i, 3);
        if (ss == "PS4" || ss == "PS5") {
            s = s.substr(0, i + 2) + s.substr(i + 3);
            i--;
        }
    }
    cout << s << '\n';
}

// 주어진 대문자/숫자 문자열에서 PS4, PS5가 나올 때 숫자를 지운 결과 출력하기