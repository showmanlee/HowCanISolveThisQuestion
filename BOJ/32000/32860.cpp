// 수수수수퍼노바
// https://www.acmicpc.net/problem/32860

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    string res = "SN " + to_string(n);
    if (m <= 26) {
        res += 'A' + m - 1;
    } else {
        m--;
        int a = m / 26, b = m % 26;
        res += ('a' + a - 1);
        res += ('a' + b);
    }
    cout << res << '\n';
}

// 주어진 러시아어의 영어로 읽는 방법 출력하기