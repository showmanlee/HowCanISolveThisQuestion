// 연속인가? ?
// https://www.acmicpc.net/problem/26517

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    long long x, a, b, c, d;
    cin >> x >> a >> b >> c >> d;
    if (a * x + b == c * x + d) {
        cout << "Yes " << (a * x + b) << '\n';
    } else {
        cout << "No\n";
    }
}

// ax + b와 cx + d를 구성하는 x와 abcd가 주어질 때, 두 식의 값이 동일한지 판정하기

// 문제 설명을 직관적으로 하면 그렇다는 거지