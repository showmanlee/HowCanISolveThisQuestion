// 4-LSB
// https://www.acmicpc.net/problem/32685

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    a %= 16;
    b %= 16;
    c %= 16;
    int res = a * 256 + b * 16 + c;
    cout.width(4);
	cout.fill('0');
    cout << res << '\n';
}

// 세 십진수의 마지막 비트 4개를 따서 서로 이어붙여서 십진수로 만든 결과 출력하기