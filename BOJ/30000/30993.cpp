// 자동차 주차
// https://www.acmicpc.net/problem/30993

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long fact(long long n) {
    long long ret = 1;
    for (long long i = 2; i <= n; i++) {
        ret *= i;
    }
    return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    long long n, a, b, c;
    cin >> n >> a >> b >> c;
    long long ret = fact(n) / (fact(a) * fact(b) * fact(c));
    cout << ret << '\n';
}

// 빨간색 a개, 초록색 b개, 파란색 c개를 n칸에 배치하는 경우의 수 출력하기

// 조합식