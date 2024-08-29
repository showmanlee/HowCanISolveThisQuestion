// ID Key
// https://www.acmicpc.net/problem/9773

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int a = 0;
        for (char c : s) {
            a += c - '0';
        }
        int b = stoi(s.substr(10)) * 10;
        int res = a + b;
        if (res >= 10000) {
            res %= 10000;
        } else if (res < 1000) {
            res += 1000;
        }
        cout.width(4);
	    cout.fill('0');
        cout << res << '\n';
    }
}

// 주어진 13자리 수의 각 자리 합과 마지막 3자리수 * 10을 더하고 뒤 4자리만 남기거나 1000을 더해 4자리수로 만든 결과 출력하기

// 13자리 수는 문자열로 받는 게 편함