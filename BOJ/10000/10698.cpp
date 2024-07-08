// Ahmed Aly
// https://www.acmicpc.net/problem/10698

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        int a, b, x;
        char c, _;
        cin >> a >> c >> b >> _ >> x;
        bool res = (a + (c == '+' ? b : -b) == x);
        cout << "Case " << t << ": " << (res ? "YES" : "NO") << '\n';
    }
}

// a ( ) b = x 꼴의 수식이 참인지 판정하기

// 더하기 빼기만 나오고 공백으로 분리되어 나오므로 입력받아 조건식을 태우면 됨