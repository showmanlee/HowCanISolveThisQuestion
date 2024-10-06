// 햄버거 정렬
// https://www.acmicpc.net/problem/32399

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int res = 1;
    if (s == "(1)") {
        res = 0;
    } else if (s == ")1(") {
        res = 2;
    }
    cout << res << '\n';
}

// (1)로 구성된 문자열이 (1) 형태가 되기 위해 필요한 이동 횟수 구하기