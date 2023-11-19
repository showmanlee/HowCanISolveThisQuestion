// 관공... 어찌하여 목만 오셨소...
// https://www.acmicpc.net/problem/30501

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
        string s;
        cin >> s;
        if (s.find("S") != string::npos) {
            cout << s << '\n';
        }
    }
}

// 대문자 문자열들 중 S가 들어간 문자열 찾아 출력하기

// find