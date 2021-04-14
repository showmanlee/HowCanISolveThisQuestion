// 부분 문자열
// https://www.acmicpc.net/problem/6550

#include <iostream>
#include <string>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s, t;
    while (cin >> s) {
        cin >> t;
        int idx = 0;
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == s[idx]) {
                idx++;
                if (idx == s.length())
                    break;
            }
        }
        cout << (idx == s.length() ? "Yes" : "No") << '\n';
    }
}

// s가 t의 부분 문자열인가? = t 안에 s를 구성하는 문자가 (중간에 다른 문자가 끼더라도) 순서대로 등장하는가?
// t의 문자들을 순회하다가 s의 문자를 발견하면 s 문자 인덱스를 하나 추가해준다
// 이후 모든 문자를 찾았다면 성공, 그렇지 않았다면 실패
// 중단점이 제대로 주어지지 않음에 주의