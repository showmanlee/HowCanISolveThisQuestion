// Sticky Keys
// https://www.acmicpc.net/problem/31656

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);
    string res;
    char prev = '/';
    for (char c : s) {
        if (c != prev) {
            res += c;
        }
        prev = c;
    }
    cout << res;
}

// 주어진 공백 포함 영어/숫자 문자열에서 연속으로 같은 문자는 한 글자르 줄여서 출력하기

// 순회하면서 줄여서 출력하기