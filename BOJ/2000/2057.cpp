// 팩토리얼 분해
// https://www.acmicpc.net/problem/2057

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long fact[21];
bool res = false;

void f(unsigned long long n, int p) {
    if (n == 0) {
        res = true;
        return;
    }
    if (res || p == -1) {
        return;
    }
    if (n >= fact[p]) {
        f(n - fact[p], p - 1);
    }
    f(n, p - 1);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    fact[0] = 1;
    for (unsigned long long i = 1; i <= 20; i++) {
        fact[i] = fact[i - 1] * i;
    }
    unsigned long long n;
    cin >> n;
    if (n != 0) {
        f(n, 20);
    }

    cout << (res ? "YES" : "NO") << '\n';
}

// 주어진 정수를 1개 이상의 서로 다른 팩토리얼의 합으로 만들 수 있는지 확인하기

// 수 범위는 unsigned long long - 20!까지 가능함
// 그렇기에 20!부터 0!까지 차례로 빼가면서 되는지 확인해볼 수 있음