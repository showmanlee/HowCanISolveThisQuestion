// No Duplicates
// https://www.acmicpc.net/problem/15098

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    map<string, bool> v;
    string s;
    bool res = true;
    while (cin >> s) {
        if (v[s]) {
            res = false;
        }
        v[s] = true;
    }
    cout << (res ? "yes" : "no") << '\n';
}

// 주어진 대문자 단어 중 중복된 단어가 있는지 확인하기