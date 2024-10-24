// Rotating letters
// https://www.acmicpc.net/problem/6750

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    string key = "IOSHZXN";
    bool res = true;
    for (char c : s) {
        if (find(key.begin(), key.end(), c) == key.end()) {
            res = false;
            break;
        }
    }
    cout << (res ? "YES" : "NO") << '\n';
}

// 주어진 대문자 문자열이 모두 180도로 돌려도 같게 읽히는 문자로 구성되었는지 확인하기