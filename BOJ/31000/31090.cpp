// 2023은 무엇이 특별할까?
// https://www.acmicpc.net/problem/31090

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        int p = n % 100;
        int m = n + 1;
        cout << (m % p == 0 ? "Good" : "Bye") << '\n';
    }
}

// 4자리 자연수 n의 뒷 두 자리로 n + 1이 나누어떨어지는지 확인하기

// 확인해주세요!