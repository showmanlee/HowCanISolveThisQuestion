// Jõululaul
// https://www.acmicpc.net/problem/29895

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        long long p = i * (n - i + 1);
        cout << p << '\n';
    }
}

// 1일차에 1 1개, 2일차에 1 1개와 2 2개... 이런 식으로 n일까지 받을 때, n일차에 받게 되는 각 종류 구하기