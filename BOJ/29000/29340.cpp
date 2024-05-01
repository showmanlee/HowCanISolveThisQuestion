// Отряд
// https://www.acmicpc.net/problem/29340

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;
    string res;
    for (int i = 0; i < a.length(); i++) {
        res += max(a[i], b[i]);
    }
    cout << res << '\n';
}

// 길이가 같은 두 수에서 같은 자릿수에 있는 숫자 중 더 높은 숫자들로 수 만들기

// 문자열로 받아서 계산