// Broken Calculator
// https://www.acmicpc.net/problem/24830

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long res = 1;
    for (int i = 0; i < n; i++) {
        long long a, b;
        char c;
        cin >> a >> c >> b;
        if (c == '+') {
            res = a + b - res;
        } else if (c == '-') {
            res = (a - b) * res;
        } else if (c == '*') {
            res = (a * b) * (a * b);
        } else if (c == '/') {
            res = (a + 1) / 2;
        }
        cout << res << '\n';
    }
}

// 더하기는 a+b-(이전값), 빼기는 (a-b)*(이전값), 곱하기는 (a*b)^2, 나누기는 (a+1)/2로 계산하는 계산기에서 초기값이 1일 때, 계산 결과 차례로 구하기 