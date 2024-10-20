// 시계탑
// https://www.acmicpc.net/problem/31561

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    float n;
    cin >> n;
    if (n <= 30) {
        n /= 2.f;
    } else {
        n = 15.f + (n - 30.f) * 3.f / 2.f;
    }
    cout << fixed;
    cout.precision(1);
    cout << n << '\n';
}

// 15분은 2배의 속도로, 나머지 45분은 2/3의 속도로 분침이 도는 시계에서 분침이 가리키는 분이 주어졌을 때, 실제 분 구하기