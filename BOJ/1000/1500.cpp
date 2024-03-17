// 최대 곱
// https://www.acmicpc.net/problem/1500

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int s, k;
    cin >> s >> k;
    unsigned long long res = 1;
    int p = s % k;
    for (int i = 0; i < k; i++) {
        unsigned long long t = s / k;
        if (p > 0) {
            p--;
            t++;
        }
        res *= t;
    }
    cout << res << '\n';
}

// 합이 s인 k개의 정수 중 가장 곱이 높게 나오는 결과 출력하기

// k개의 정수가 s // k 또는 s // k + 1이어야 최대가 보장됨 - 큰 수가 작은 수로 인해 줄어들지 않도록