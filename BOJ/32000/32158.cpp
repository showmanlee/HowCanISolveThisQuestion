// SWAPC
// https://www.acmicpc.net/problem/32158

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p, c;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') {
            p.push_back(i);
        } else if (s[i] == 'C') {
            c.push_back(i);
        }
    }
    for (int i = 0; i < min(p.size(), c.size()); i++) {
        swap(s[p[i]], s[c[i]]);
    }
    cout << s << '\n';
}

// 대문자 문자열의 P와 C가 등장한 순서대로 서로 자리를 바꾼 결과 출력하기