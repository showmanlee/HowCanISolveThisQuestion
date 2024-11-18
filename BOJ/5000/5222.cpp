// Vigenère Cipher
// https://www.acmicpc.net/problem/5222

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
        string p, s;
        cin >> p >> s;
        string res;
        for (int i = 0; i < s.length(); i++) {
            int n = p[i % p.length()] - 'A';
            res += 'A' + ((s[i] - 'A' + n) % 26);
        }
        cout << "Ciphertext: " << res << '\n';
    }
}

// 대문자 문자열을 키로 하는 시저 암호 문자열 구하기