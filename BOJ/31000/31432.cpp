// 소수가 아닌 수 3
// https://www.acmicpc.net/problem/31432

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> res;
    }
    res *= 111;
    cout << "YES\n" << res << '\n';

}

// 주어진 숫자들을 중복 포함 사용하여 소수가 아닌 수 구하기

// 숫자에서 111을 곱하면 모두 소수가 아니게 됨