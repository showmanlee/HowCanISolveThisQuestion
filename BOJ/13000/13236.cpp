// Collatz Conjecture
// https://www.acmicpc.net/problem/13236

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    while (true) {
        cout << n;
        if (n == 1) {
            cout << '\n';
            break;
        }
        cout << ' ';
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
    }
}

// 주어진 정수를 홀수일 때 n*3+1, 짝수일 때 n/2를 반복하여 1로 만들기