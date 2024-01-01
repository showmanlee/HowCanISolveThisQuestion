// KOREA 문자열 만들기
// https://www.acmicpc.net/problem/30700

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    char cur = 'A';
    int res = 0;
    for (char c : s) {
        if ((cur == 'A' && c == 'K') || (cur == 'K' && c == 'O') || (cur == 'O' && c == 'R') || (cur == 'R' && c == 'E') || (cur == 'E' && c == 'A')) {
            cur = c;
            res++;
        }
    }
    cout << res << '\n';
}

// 주어진 대문자 문자열의 문자들을 지워 만들 수 있는 KOREAKO... 꼴의 문자열의 최대 길이 구하기

// 항상 K->O->R->E->A 순으로 찍혀야 함 - 문자 순회하면서 해당 순서대로 문자를 확보해갑시다