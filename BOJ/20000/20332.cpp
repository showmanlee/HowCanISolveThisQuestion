// Divvying Up
// https://www.acmicpc.net/problem/20332

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        sum += p;
    }
    cout << (sum % 3 ? "no" : "yes") << '\n';
}

// 주어진 수의 합이 3으로 나누어떨어지는지 확인하기

// 계산하면 되지요