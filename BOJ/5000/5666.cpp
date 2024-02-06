// Hot Dogs
// https://www.acmicpc.net/problem/5666

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    cout << fixed;
    cout.precision(2);

    float a, b;
    while (cin >> a) {
        cin >> b;
        cout << (a / b) << '\n';
    }
}

// 두 자연수 a, b가 주어질 때, a / b를 소수 둘째자리까지 구하기

// 구할게요