// 和の判定 (Sum Checker)
// https://www.acmicpc.net/problem/31607

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    int res = (a + b == c || a + c == b || b + c == a ? 1 : 0);
    cout << res << '\n';
}

// 세 수가 주어질 때, 두 수의 합으로 다른 하나의 수를 만들 수 있는지 판정하기