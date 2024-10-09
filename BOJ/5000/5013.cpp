// Death Knight Hero
// https://www.acmicpc.net/problem/5013

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int t = 0; t < n; t++) {
        string s;
        cin >> s;
        res++;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == 'C' && s[i + 1] == 'D') {
                res--;
                break;
            }
        }
    }
    cout << res << '\n';
}

// 주어진 문자열들에서 "CD"가 없는 문자열 개수 찾기