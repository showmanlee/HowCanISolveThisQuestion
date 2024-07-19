// Bunnies
// https://www.acmicpc.net/problem/26529

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<int> fib(46);
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= 45; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int p;
        cin >> p;
        cout << fib[p] << '\n';
    }
}

// p번째 피보나치 수 구하기