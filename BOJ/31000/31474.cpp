// 양갈래 짝 맞추기
// https://www.acmicpc.net/problem/31474

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;
    long long res = 1;
    for (int i = 2; i <= n; i += 2) {
        res *= (i * (i - 1)) / 2;
        res /= (i / 2);
    }
    cout << res << '\n';
}

// 짝수 n명이 2명씩 마주앉는 경우의 수 구하기