// 딘슨힌 문제 (Small)
// https://www.acmicpc.net/problem/25494

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << min(a, min(b, c)) << '\n';
	}
}

// a, b, c가 주어질 때 1~a, 1~b, 1~c를 만족하는 x, y, z가 (x % y) == (y % z) == (z % x)를 만족하게 되는 순서쌍 개수 구하기

// 그냥 브루트포스로 대입해봐도 풀리는 문제긴 하지만, 그렇게 풀 수 없는 Large 문제도 있음 - 그러니까 Large 정답으로 이것도 미리 풀어버리자
// 일단 기본적으로 x % y <= x, y % z <= y, z % x <= z이다 - 나머지 연산을 하는데 x 이상으로 값이 나올 수는 없음
// 다만 여기서 x % y == x일 경우(즉 x < y일 경우), 나머지 식의 대소관계가 x < y < z < x가 되어버리므로 조건에 맞는 수가 나올 수 없음
// 따라서 x % y < x의 경우만 생각하면 되는데, 아까 구한 대소관계를 응용하면 x <= y <= z <= x 꼴을 만들 수 있음
// 그리고 이 식을 만족하는 경우의 수는 x == y == z뿐 - 따라서 x, y, z 중 가장 작은 수로 통일을 시켜줘야 답이 되는 것