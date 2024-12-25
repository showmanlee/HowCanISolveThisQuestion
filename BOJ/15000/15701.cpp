// 순서쌍
// https://www.acmicpc.net/problem/15701

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;
    int res = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res += 2;
            if (i * i == n) {
                res--;
            }
        }
    }
    cout << res << '\n';    
}

// 두 자연수의 곱이 n인 순서쌍의 개수 구하기