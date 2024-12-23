// Which Number Kind Is It?
// https://www.acmicpc.net/problem/32682

#include <iostream>
#include <string>
#include <cmath>
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
        string res;
        if (n % 2 == 1) {
            res += 'O';
        }
        if (sqrt(n) == (int)sqrt(n)) {
            res += 'S';
        }
        if (res.empty()) {
            res = "EMPTY";
        }
        cout << res << '\n';
    }
}

// 주어진 수가 홀수이며 제곱수인지 확인하기