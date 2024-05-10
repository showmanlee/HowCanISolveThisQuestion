// 단원평가
// https://www.acmicpc.net/problem/31798

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0 || b == 0) {
        cout << (c * c - (a == 0 ? b : a)) << '\n';
    } else {
        cout << (int)sqrt(a + b) << '\n';
    }
}

// a + b = c^2 에서 세 수 중 하나가 비어있을 때, 빈 수 구하기