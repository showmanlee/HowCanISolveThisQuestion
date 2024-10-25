// Cookie Piles
// https://www.acmicpc.net/problem/30143

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n, a, d;
        cin >> n >> a >> d;
        int res = (a * n) + (d * n * (n - 1) / 2);
        cout << res << '\n';
    }
}

// a항에서 시작하는 등차가 d인 길이 n의 등차수열의 합 구하기