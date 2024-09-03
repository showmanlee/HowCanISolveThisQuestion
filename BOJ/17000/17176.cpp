// 암호해독기
// https://www.acmicpc.net/problem/17176

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<int> v(53);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        v[p]++;
    }
    cin.ignore();
    string s;
    getline(cin, s);
    bool res = true;
    for (char c : s) {
        if (c == ' ') {
            v[0]--;
        } else if (isupper(c)) {
            v[c - 'A' + 1]--;
        } else if (islower(c)) {
            v[c - 'a' + 27]--;
        }
    }
    for (int i = 0; i <= 52; i++) {
        if (v[i] != 0) {
            res = false;
            break;
        }
    }
    cout << (res ? "y" : "n") << '\n';
}

// 공백, 대문자, 소문자가 각각의 번호로 변환되어 무작위로 섞인 배열이 있을 때, 주어진 문자열이 이에 만족하는지 확인하기