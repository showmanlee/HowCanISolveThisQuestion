// Послание
// https://www.acmicpc.net/problem/28967

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string c, s;
    cin >> c >> s;
    int idx = 0;
    int res = 0;
    for (char p : s) {
        if (p == c[idx]) {
            idx++;
            if (idx == c.length()) {
                res++;
                idx = 0;
            }
        }
    }
    cout << res << '\n';
}

// c를 연속해서 쓴 문자열 사이사이에 알파벳을 랜덤으로 넣었을 때, 들어간 c의 개수 구하기