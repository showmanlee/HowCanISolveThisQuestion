// ZOAC 5
// https://www.acmicpc.net/problem/26594

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int res = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[0]) {
            res++;
        } else {
            break;
        }
    }
    cout << res << '\n';
}

// 같은 알파벳을 연속으로 입력한 문자열이 주어질 때, 알파벳당 연속으로 입력한 개수 구하기

// 연속 입력이 들어오지 않음이 보장되므로 첫 알파벳과 그 반복 횟수만 보면 됨