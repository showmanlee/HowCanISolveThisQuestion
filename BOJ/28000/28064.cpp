// 이민희진
// https://www.acmicpc.net/problem/28064

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
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string a, b;
            int p = v[i].length();
            int q = v[j].length();
            bool pass = false;
            for (int k = 1; k <= min(p, q); k++) {
                a = v[i][p - k] + a;
                b += v[j][k - 1];
                if (a == b) {
                    res++;
                    pass = true;
                    break;
                }
            }
            if (pass) {
                continue;
            }
            a = b = "";
            for (int k = 1; k <= min(p, q); k++) {
                a = v[j][q - k] + a;
                b += v[i][k - 1];
                if (a == b) {
                    res++;
                    pass = true;
                    break;
                }
            }
        }
    }
    cout << res << '\n';
}

// 주어진 문자열들 중 앞뒤로 겹치게 붙일 수 있는 문자열 쌍의 수 구하기