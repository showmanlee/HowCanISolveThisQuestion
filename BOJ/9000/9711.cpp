// 피보나치
// https://www.acmicpc.net/problem/9711

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        int p, q;
        cin >> p >> q;
        vector<long long> fib(p);
        fib[0] = fib[1] = 1;
        for (int i = 2; i < p; i++) {
            fib[i] = (fib[i - 2] + fib[i - 1]) % q;
        }
        if (q == 1) {
            fib[p - 1] = 0;
        }
        cout << "Case #" << t << ": " << fib[p - 1] << '\n';
    }
}

// 피보나치 p번째 수를 q로 나머지 연산한 결과 출력하기

// 나머지 잘 보면서 계산하시면 됩니다 - 피보나치는 n으로 풀 수 있는 물건
// 그런데 만약 100%에서 틀린다면, q가 1인 경우를 생각해보시길 - % 1 == 0