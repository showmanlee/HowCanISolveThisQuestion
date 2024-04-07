// SciComLove (2024)
// https://www.acmicpc.net/problem/31746

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s = "SciComLove";
    if (n % 2 == 1) {
        reverse(s.begin(), s.end());
    }
    cout << s << '\n';
}

// 주어진 문자열을 n번 뒤집은 결과 출력하기

// 짝수번 뒤집으면 원래대로 돌아옴