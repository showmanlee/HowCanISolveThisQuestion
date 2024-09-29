// Skew Binary
// https://www.acmicpc.net/problem/4678

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    while (true) {
        string s;
        cin >> s;
        if (s == "0") {
            break;
        }
        reverse(s.begin(), s.end());
        int res = 0;
        int idx = 1;
        for (char c : s) {
            int p = pow(2, idx) - 1;
            res += (c - '0') * p;
            idx++;
        }
        cout << res << '\n';
    }
}

// 각 자릿수가 2^n - 1을 나타내는 변형 이진수가 주어질 때, 십진수로 변환한 결과 출력하기