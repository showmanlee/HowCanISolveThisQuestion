// GCD
// https://www.acmicpc.net/problem/5344

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a < b) {
            swap(a, b);
        }
        while (b != 0) {
            int p = a % b;
            a = b;
            b = p;
        }
        cout << a << '\n';
    }
}

// 두 자연수의 최대공약수 구하기