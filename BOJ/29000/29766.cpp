// DKSH 찾기
// https://www.acmicpc.net/problem/29766

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
    for (int i = 0; i < s.length() - 3; i++) {
        if (s.substr(i, 4) == "DKSH") {
            res++;
        }
    }
    cout << res << '\n';
}

// 주어진 대문자 문자열에서 "DKSH" 개수 찾기

// substr 순환