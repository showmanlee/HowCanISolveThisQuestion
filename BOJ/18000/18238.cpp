// ZOAC 2
// https://www.acmicpc.net/problem/18238

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    s = 'A' + s;
    int res = 0;
    for (int i = 1; i < s.length(); i++) {
        int a = s[i - 1] - 'A';
        int b = s[i] - 'A';
        res += min(abs(b - a), 26 - abs(b - a));
    }
    cout << res << '\n';
}

// 알파벳이 원형으로 나열된 원형 환에서 A부터 시작해 주어진 문자열을 순서대로 도는 최단 거리 구하기