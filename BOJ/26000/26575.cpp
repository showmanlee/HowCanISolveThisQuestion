// Pups
// https://www.acmicpc.net/problem/26575

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    cout << fixed;
    cout.precision(2);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double a, b, c;
        cin >> a >> b >> c;
        cout << '$' << (c * b * a) << '\n';
    }
}

// 실수 a, b, c가 주어질 때, a * b * c 구하기