// 행운의 티켓
// https://www.acmicpc.net/problem/1639

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int res = 0;
    for (int n = 2; n <= s.length(); n += 2) {
        for (int i = 0; i <= s.length() - n; i++) {
            string ss = s.substr(i, n);
            int a = 0, b = 0;
            for (int j = 0; j < n; j++) {
                if (j < n / 2) {
                    a += ss[j] - '0';
                } else {
                    b += ss[j] - '0';
                }
            }
            if (a == b) {
                res = max(res, n);
                break;
            }
        }
    }
    cout << res << '\n';
}

// 주어진 숫자 문자열의 길이가 짝수인 부분 문자열 중 양쪽 절반 자리들의 합이 같은 경우의 부분 문자열 최대 길이 출력하기

// 직접 다 찾아봅시다 - 거리는 충분함