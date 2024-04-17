// 三連続 (Three Consecutive)
// https://www.acmicpc.net/problem/31636

#include <iostream>
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
    bool res = false;
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == 'o' && s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            res = true;
            break;
        }
    }
    cout << (res ? "Yes" : "No") << '\n';
}

// o와 x로만 구성된 문자열에서 3연속으로 o가 있는지 확인하기

// 순서대로 확인해본다