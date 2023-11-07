// 수 이어 쓰기 3
// https://www.acmicpc.net/problem/2154

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
    for (int i = 1; i <= n; i++) {
        s += to_string(i);
    }
    int res = s.find(to_string(n)) + 1;
    cout << res << '\n';
}

// 1부터 n까지 이어 쓴 문자열에서 n이 처음으로 등장하는 위치 구하기

// string에서 해당 문자열 찾는 함수 사용 - c++에서는 s.find