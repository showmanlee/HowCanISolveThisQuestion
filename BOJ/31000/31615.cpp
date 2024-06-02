// 桁 (Digit)
// https://www.acmicpc.net/problem/31615

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int p = a + b;
    int res = 0;
    while (p > 0) {
        res++;
        p /= 10;
    }
    cout << res << '\n';
}

// a + b가 몇자리수인지 출력하기