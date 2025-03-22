// 폰트
// https://www.acmicpc.net/problem/9997

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, res;
int v[26];

void f(int p, int b) {
    if (p == n) {
        if (b == (1 << 26) - 1) {
			res++;
		}
        return;
    }
	f(p + 1, b);
    f(p + 1, b | v[p]);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (auto c : s) {
			v[i] |= (1 << (c - 'a'));
		}
    }
    f(0, 0);
    cout << res << '\n';
}

// 주어진 소문자 단어들을 하나씩만 골라 모든 알파벳을 쓸 수 있는 경우의 수 구하기