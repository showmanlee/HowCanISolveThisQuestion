// 엑셀
// https://www.acmicpc.net/problem/2757

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    while (true) {
        string s;
        cin >> s;
        if (s == "R0C0") {
            break;
        }
        string r, c;
        int flag = 0;
        for (char ch : s) {
            if (ch == 'R') {
                flag = 1;
            } else if (ch == 'C') {
                flag = 2;
            } else {
                if (flag == 1) {
                    r += ch;
                } else {
                    c += ch;
                }
            }
        }
        int cc = stoi(c) - 1;
        string cr;
        while (cc >= 0) {
            int p = cc % 26;
            cr = (char)('A' + p) + cr;
            cc = cc / 26 - 1;
        }
        if (cr.empty()) {
            cr = "A";
        }
        cout << cr << r << '\n';
    }
}

// 행 번호와 열 번호가 주어질 때, 이를 엑셀 표기 방식으로 변환하기

// 행은 번호 그대로, 열은 변형 26진수로 변환하여 출력 - 26진수 자리 바꿀 때 1씩 뺴줘야 함에 주의