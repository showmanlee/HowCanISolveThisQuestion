// ZOAC 6
// https://www.acmicpc.net/problem/30045

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
        for (int i = 0; i < s.length() - 1; i++) {
            if ((s[i] == '0' && s[i + 1] == '1') || (s[i] == 'O' && s[i + 1] == 'I')) {
                res++;
                break;
            }
        }
    }
    cout << res << '\n';
}

// 주어진 문자열들에 포함된 "01" 또는 "OI"이 포함된 문자열의 개수 구하기