// Greetings!
// https://www.acmicpc.net/problem/17548

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    cout << "h";
    for (int i = 0; i < (s.length() - 2) * 2; i++) {
        cout << "e";
    }
    cout << "y\n";
}

// hey 형태로 주어지는 문자열을 받고 e의 개수가 2배인 문자열 출력하기

// 세어주면서 하면 됩니다