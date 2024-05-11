// !!초콜릿 중독 주의!!
// https://www.acmicpc.net/problem/31458

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
        int a = 0, b = 0;
        bool t = false;
        bool res = false;
        for (char c : s) {
            if (c != '!') {
                t = true;
                res = (c == '1');
                continue;
            }
            if (!t) {
                a++;
            } else {
                b++;
            }
        }
        while (b > 0) {
            res = true;
            b--;
        }
        while (a > 0) {
            res = !res;
            a--;
        }
        cout << res << '\n';
    }
}

// 0 또는 1에 팩토리얼 및 NOT 연산을 가한 결과 출력하기

// 팩토리얼은 무조건 1, NOT은 NOT - 이 순서대로 계산하기