// Letter Cookies
// https://www.acmicpc.net/problem/11117

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        string p;
        cin >> p;
        vector<int> cnt(26);
        for (char c : p) {
            cnt[c - 'A']++;
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            vector<int> v(26);
            for (char c : s) {
                v[c - 'A']++;
            }
            bool res = true;
            for (int j = 0; j < 26; j++) {
                if (cnt[j] < v[j]) {
                    res = false;
                    break;
                }
            }
            cout << (res ? "YES" : "NO") << '\n';
        }
    }
}

// 주어진 자연수를 짝수일 땐 n * 3 + 1, 홀수일 땐 n / 2를 반복해 최종적으로 1로 만들 때, 필요한 횟수 구하기