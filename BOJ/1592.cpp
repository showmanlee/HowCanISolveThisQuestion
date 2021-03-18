// 영식이와 친구들
// https://www.acmicpc.net/problem/1592

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, m, l;
	cin >> n >> m >> l;
	vector<int> count(n);
	int holder = 0;
	int res = 0;
	count[0] = 1;
	while (true) {
		if (count[holder] % 2 == 0)
			holder = (holder + l) % n;
		else
			holder = (holder - l + n) % n;
		count[holder]++;
		res++;
		if (count[holder] >= m)
			break;
	}
	cout << res << '\n';
}

// 시계방향으로 둘러 앉은 사람들이 공을 던져 누군가가 m번 받기 전까지 아래와 같은 규칙으로 공을 던질 때, m번째로 공을 받는 사람이 나올 때 공을 던진 총 횟수는?
// - 자신이 공을 횟수가 홀수인 경우 시계방향(+)으로 l번째 있는 사람에게, 짝수인 경우 반시계방향(-)으로 l번째 있는 사람에게 던진다
// 1번째 사람을 0번째 사람으로 만든 후, 각 사람마다 공을 받은 횟수를 기록하며 나머지 연산과 반복문을 활용하여 돌린다