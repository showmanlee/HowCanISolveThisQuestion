// Welcome to SMUPC!
// https://www.acmicpc.net/problem/29699

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s = "WelcomeToSMUPC";
    int n;
    cin >> n;
    n--;
    cout << s[n % s.length()] << '\n';
}

// WelcomeToSMUPC가 무한히 반복되는 문자열에서 n번째 문자 출력하기