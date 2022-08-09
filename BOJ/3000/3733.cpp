// Shares
// https://www.acmicpc.net/problem/3733

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b;
    while (cin >> a) {
        cin >> b;
        cout << (b / (a + 1)) << '\n';
    }
}

// 두 자연수 a, b가 주어질 때, b / (a + 1)의 몫 출력하기

// 하면 됩니다 - 특별한 중단점이 주어지지 않으므로 while cin 붙이고