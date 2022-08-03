// 한다 안한다
// https://www.acmicpc.net/problem/5789

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int p = s.length() / 2;
        cout << (s[p] == s[p - 1] ? "Do-it" : "Do-it-Not") << '\n'; 
    }
}

// 0과 1로만 주어진 문자열에서 양 끝 문자를 지워갈 때, 마지막으로 남는 문자가 같은지 다른지 판정하기

// 결국 가장 가운데 두 글자만 남을 것 - 주어지는 문자열의 길이는 언제나 짝수
// 그렇기에 자르는 과정 없이 가운데 두 글자 보고 판정하기