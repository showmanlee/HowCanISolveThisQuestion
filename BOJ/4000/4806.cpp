// 줄 세기
// https://www.acmicpc.net/problem/4806

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);

    string s;
    int res = 0;
    while(getline(cin, s)) {
        res++;
    }
    cout << res << '\n';
}

// 공백이 있을 수 있는 문자열이 여러 줄 들어올 때, 들어온 줄 수 세기

// 공백이 있는 줄을 받을 때는 getline을 사용한다 - 그리고 getline 역시 while 안에 넣어 들어올 때까지만 입력을 받을 수 있음
// 이를 이용해 줄 수를 세서 출력한다