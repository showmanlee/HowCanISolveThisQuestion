// Silnia
// https://www.acmicpc.net/problem/8558

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res = (res * i) % 10;
    }
    cout << res << '\n';
}

// n!의 1의 자리 구하기

// 계속 곱해주면서 1의 자리만 남겨줍시다