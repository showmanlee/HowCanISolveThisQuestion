// #TheDress
// https://www.acmicpc.net/problem/31368

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    cout << fixed;
    cout.precision(10);

    int n;
    cin >> n;
    cin.ignore();
    double a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        bool x = false, y = false, z = false, w = false;
        int p = s.length();
        for (int j = 0; j < p; j++) {
            if (p - j >= 4) {
                string ss = s.substr(j, 4);
                if (ss == "blue") {
                    x = true;
                } else if (ss == "gold") {
                    w = true;
                }
            }
            if (p - j >= 5) {
                string ss = s.substr(j, 5);
                if (ss == "black") {
                    y = true;
                } else if (ss == "white") {
                    z = true;
                }
            }
        }
        if (x && y) {
            a += 1;
        } else if (z && w) {
            b += 1;
        } else {
            c += 1;
        }
    }
    a = a / n * 100;
    b = b / n * 100;
    c = c / n * 100;
    cout << a << '\n' << b << '\n' << c << '\n';
}

// 주어진 소문자 문자열들 중 "blue" "black"이 동시에 포함된 문자열과 "white" "gold"가 동시에 포함된 문자열, 둘 다 아닌 문자열의 비율 구하기

// 서브스트링 찾기