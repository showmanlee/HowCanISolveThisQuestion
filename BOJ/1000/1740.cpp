// 거듭제곱
// https://www.acmicpc.net/problem/1740

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;
    long long p = 1, res = 0;
    while (n > 0) {
        res += p * (n % 2);
        n /= 2;
        p *= 3;
    }
    cout << res << '\n';
}

// 하나 이상의 서로 다른 3의 거듭제곱의 합으로 만들 수 있는 수 중 n번째로 작은 수 구하기

// 결국 비트마스킹 문제 - 3^2 > 3^1 + 3^0
// 참고로 5천억은 2^39 정도 되는 수