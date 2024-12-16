// 금민수의 개수
// https://www.acmicpc.net/problem/1527

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

long long n, m, res;

void f(long long p) {
    if (p > m) {
        return;
    } else if (p >= n) {
        res++;
    }
    f(p * 10 + 4);
    f(p * 10 + 7);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> n >> m;
    f(4);
    f(7);
    cout << res << '\n';
}

// n 이상 m 이하의 4와 7로만 구성된 자연수 개수 구하기