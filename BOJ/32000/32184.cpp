// 디미고에 가고 싶어!
// https://www.acmicpc.net/problem/32184

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int res = 0;
    if (a % 2 == 0) {
        res++;
        a++;
    }
    if (b % 2 == 1) {
        res++;
        b--;
    }
    res += (b - a + 1) / 2;
    cout << res << '\n';
}

// 양쪽 페이지 책에서 연속된 페이지 2개는 한 번에 찍을 수 있을 때, 특정 페이지 구간에서 찍는 최소 횟수 구하기