// 연세여 사랑한다
// https://www.acmicpc.net/problem/25915

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	char c;
	cin >> c;
	int res = abs(c - 'I') + 84;
	cout << res << '\n';
}

// A부터 Z까지 일렬로 나열된 판에서 c에서 시작해 ILOVEYONSEI를 입력하는데 필요한 이동 거리는?

// 일렬로 나열되어 있고 원형도 아니기 떄문에 최단거리는 일직선이 될 수밖에 없음 - 따라서 글자간 거리 84에 c에서 I까지의 거리를 더해주면 됨