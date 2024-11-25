// 아카라카 2
// https://www.acmicpc.net/problem/32652

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string res = "AKA";
    for (int i = 0; i < n; i++) {
        res += "RAKA";
    }
    cout << res << '\n';
}

// AKARAKA가 정확히 n번 등장하는 가장 짧은 팰린드롬 출력하기