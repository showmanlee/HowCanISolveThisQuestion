// 라면 공식
// https://www.acmicpc.net/problem/30007

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int a, b, x;
        cin >> a >> b >> x;
        int res = a * (x - 1) + b;
        cout << res << '\n';
    }
}

// a(x - 1) + b 출력하기