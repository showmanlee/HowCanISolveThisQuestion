// UOSPC 세기
// https://www.acmicpc.net/problem/30822

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (char c : s) {
        cnt[c - 'a']++;
    }
    cout << min(min(min(cnt['u' - 'a'], cnt['o' - 'a']), cnt['s' - 'a']), min(cnt['p' - 'a'], cnt['c' - 'a'])) << '\n';
}

// 주어진 소문자 문자열의 문자들을 재조합해서 만들 수 있는 uospc 개수 세기

// 문자열에 등장한 u o s p c 중 가장 작은 개수 출력