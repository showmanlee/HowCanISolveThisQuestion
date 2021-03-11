// 팩토리얼5
// https://www.acmicpc.net/problem/1564

#include <iostream>
using namespace std;

int main(void) {
    long long n;
    cin >> n;
    long long res = 1;
    for (long long i = 1; i <= n; i++) {
        res *= i;
        while (res % 10 == 0)
            res /= 10;
        res %= 1000000000000;
    }
    res %= 100000;
    printf("%05lld\n", res);
}

// 팩토리얼의 0이 아닌 마지막 5자리 출력하기
// (n % k) + 1 === (n + 1) % k 를 활용해 만들어봅시다
// 다만 매 팩토리얼 연산을 % 100000으로만 하면 어느 순간 유효 숫자가 4자리 이하가 되어 계산이 어그러진다 - 계산 중에는 충분히 두고, 계산 후에 % 100000 하기
// 5 * 7자리 연산이 행해지므로 long long으로
// 포맷 출력은 printf로