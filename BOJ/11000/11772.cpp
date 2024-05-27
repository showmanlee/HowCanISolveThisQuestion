// POT
// https://www.acmicpc.net/problem/11772

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;
        res += pow(p / 10, p % 10);
    }
    cout << res << '\n';
}

// 정수와 한자릿수 지수가 그대로 붙은 정수로 주어질 때, 주어진 값들의 합 출력하기