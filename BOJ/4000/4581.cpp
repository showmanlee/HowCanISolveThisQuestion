// Voting
// https://www.acmicpc.net/problem/4581

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    while (true) {
        string s;
        cin >> s;
        if (s == "#") {
            break;
        }
        int y = 0, n = 0, p = 0, a = 0;
        for (char c : s) {
            if (c == 'Y') {
                y++;
            } else if (c == 'N') {
                n++;
            } else if (c == 'P') {
                p++;
            } else if (c == 'A') {
                a++;
            }
        }
        if (y + n + p <= a) {
            cout << "need quorum";
        } else {
            if (y > n) {
                cout << "yes";
            } else if (y < n) {
                cout << "no";
            } else {
                cout << "tie";
            }
        }
        cout << '\n';
    }
}

// 회의에서 찬성/반대/기권/미참석 현황이 주어질 떄, 미참석자가 절반 이상일 경우 need quorum, 그 외의 경우에는 투표 결과 출력하기

// 세 준 다음 출력한다