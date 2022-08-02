// 팬들에게 둘러싸인 홍준
// https://www.acmicpc.net/problem/14581

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    cout << ":fan::fan::fan:\n:fan::" << s << "::fan:\n:fan::fan::fan:\n";
}

// 닉네임이 주어졌을 때, 그 주변 8방향에 :fan:이 적린 문자열 출력하기

// 실제로 그렇게 출력해주면 됩니다...