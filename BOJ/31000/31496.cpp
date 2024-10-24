// 자작나무가 없소~
// https://www.acmicpc.net/problem/31496

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;
    int res = 0;
    for (int i = 0; i < n; i++) {
        string st;
        int p;
        cin >> st >> p;
        stringstream ss(st);
        string b;
        while (getline(ss, b, '_')) {
            if (b == s) {
                res += p;
                break;
            }
        }
    }
    cout << res << '\n';
}

// _로 구분된 문자열과 점수 쌍이 주어질 때, 주어진 단어가 포함된 문자열들의 점수 합 구하기