// Bedtime Reading, I
// https://www.acmicpc.net/problem/14782

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            res += i;
        }
    }
    cout << res << '\n';
}

// n의 약수의 합 구하기