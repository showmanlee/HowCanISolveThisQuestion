// 사격 내기
// https://www.acmicpc.net/problem/27960

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int res = n ^ m;
	cout << res << '\n';
}

// 1, 2, 4, 8, 16 ... 512점으로 구성된 과녁에서 두 사람이 기록한 점수가 주어지고, 다른 사람은 두 사람 중 한 사람만 맞힌 곳만 맞췄다고 할 떄, 다른 사람의 점수 구하기

// 점수 체계를 보면 알 수 있지만 비트마스킹 문제
// 두 수를 xor해서 나온 결과를 출력합시다