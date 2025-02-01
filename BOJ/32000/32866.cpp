// 코인의 신 건모
// https://www.acmicpc.net/problem/32866

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    cout << fixed;
	cout.precision(6);

    double a, b;
    cin >> a >> b;
    double p = a * (1.0 - (b / 100.0));
    double res = ((a / p) - 1.0) * 100;
    cout << res << '\n';
}

// 원금 a에서 b%를 깔 때, 다시 a로 만들기 위해서 필요한 배율 구하기