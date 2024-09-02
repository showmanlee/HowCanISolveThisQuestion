// Szyfr Cezara
// https://www.acmicpc.net/problem/8772

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        string s;
        char c;
        cin >> n >> s >> c;
        int diff = c - s[0] + 26;
        string res;
        for (int i = 0; i < n; i++) {
            int p = ((s[i] - 'a') + diff) % 26;
            res += 'a' + p;
        }
        cout << res << '\n';
    }
}

// 소문자 시저 암호문과 복호화된 첫 글자가 주어질 떄, 주어진 암호문 전체 복호화하기