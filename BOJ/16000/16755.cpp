// Magnus
// https://www.acmicpc.net/problem/16755

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    string key = "HONI";
    int idx = 0;
    int res = 0;
    for (char c : s) {
        if (c == key[idx]) {
            idx = (idx + 1) % 4;
            if (idx == 0) {
                res++;
            }
        }
    }
    cout << res << '\n';
}

// 주어진 대문자 문자열에서 문자를 빼서 만들 수 있는 HONI의 개수 구하기