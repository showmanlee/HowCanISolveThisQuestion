// Cupcake Party
// https://www.acmicpc.net/problem/24568

#include <iostream> 
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	int res = (a * 8 + b * 3) - 28;
	cout << res << '\n';
}

// 8개들이 상자와 3개들이 상자의 개수가 주어질 때, 28명의 학생에게 나눠주고 남을 컵케익의 수는?

// 계산하면 됩니다 - 컵케익은 언제나 최소 28개임이 보장됨