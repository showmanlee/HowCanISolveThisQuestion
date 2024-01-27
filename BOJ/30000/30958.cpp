// 서울사이버대학을 다니고
// https://www.acmicpc.net/problem/30958

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string n, s;
    getline(cin, n);
    getline(cin, s);
    vector<int> v(26);
    int res = 0;
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            v[c - 'a']++;
            res = max(res, v[c - 'a']);
        }
    }
    cout << res << '\n';
}

// 공백 및 문장 부호를 포함한 소문자 문자열에서 가장 많이 등장한 알파벳의 개수 구하기

// 문자 순회