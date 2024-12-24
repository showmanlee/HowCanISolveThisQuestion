// 동아리비 횡령
// https://www.acmicpc.net/problem/32621

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    bool res = false;
    for (int i = 1; i <= 999; i++) {
        if (s == to_string(i) + "+" + to_string(i)) {
            res = true;
            break;
        }
    }
    cout << (res ? "CUTE" : "No Money") << '\n';
}

// 주어진 문자열이 n+n(n = 0으로 시작하지 않는 정수) 꼴인지 구하기