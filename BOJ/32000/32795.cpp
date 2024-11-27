// Intuitive Elements
// https://www.acmicpc.net/problem/32795

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        vector<bool> v(26);
        for (char c : a) {
            v[c - 'a'] = true;
        } 
        bool res = true;
        for (char c : b) {
            if (!v[c - 'a']) {
                res = false;
                break;
            }
        }
        cout << (res ? "YES" : "NO") << '\n';
    }
}

// 주어진 소문자 문자열에 다음으로 주어진 소문자 문자들이 모두 포함되어 있는지 확인하기