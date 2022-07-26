// 팰린드롬 만들기
// https://www.acmicpc.net/problem/1213

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    vector<int> cnt(26);
    for (char c : s) {
        cnt[c - 'A']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] != 0 && cnt[i] % 2 == 1) {
            odd++;
        }
    }
    if ((s.length() % 2 == 0 && odd == 0) || (s.length() % 2 == 1 && odd == 1)) {
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                for (int j = 0; j < cnt[i] / 2; j++) {
                    cout << (char)(i + 'A');
                }
            }
        }
        if (odd) {
            for (int i = 0; i < 26; i++) {
                if (cnt[i] % 2 == 1) {
                    cout << (char)(i + 'A'); 
                }
            }
        }
         for (int i = 25; i >= 0; i--) {
            if (cnt[i] > 0) {
                for (int j = 0; j < cnt[i] / 2; j++) {
                    cout << (char)(i + 'A');
                }
            }
        }
        cout << '\n'; 
    } else {
        cout << "I'm Sorry Hansoo\n";
    }
}

// 주어진 대문자 문자열로 팰린드롬 만들기(못 만들면 I'm Sorry Hansoo 출력하기)

// 문자열 길이가 짝수이고 등장하는 문자들의 개별 개수에 홀수가 없거나, 문자열 길이가 홀수이고 등장하는 문자 중 한 종류만 홀수로 등장해야 만들 수 있음
// 만약 짝수 문자열의 경우 등장한 문자들을 절반으로 나누어 반쪽은 정순, 반쪽은 역순으로 출력한다
// 홀수 문자열의 경우 그 사이에 홀수로 등장한 문자 하나를 넣는다