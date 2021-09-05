// 제곱 ㄴㄴ 수
// https://www.acmicpc.net/problem/1016

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long int min, max;
	cin >> min >> max;

	vector<bool> passed(max - min + 1, true);
	long long idx = 2;
	while (idx * idx <= max) {
		long long p = min / (idx * idx);
		if (min % (idx * idx) != 0)
			p++;
		while (p * idx * idx <= max) {
			if (passed[p * idx * idx - min])
				passed[p * idx * idx - min] = false;
			p++;
		}
		idx++;
	}
	int res = 0;
	for (bool b : passed)
		if (b)
			res++;
	cout << res << '\n';
}

// min~max 범위 안에서 1보다 큰 제곱수로 나누어떨어지지 않는 수의 개수는?

// min은 최대 1조까지 갈 수 있고, max는 여기서 100만 만큼 커질 수 있음 - 일반적인 소수 탐색 방식으로는 무리
// 그런데 우리가 탐색해야 하는 수의 범위는 최대 100만임 - 그리고 1조는 100만의 제곱수
// 따라서 생각보다 무리하지 않고 문제를 풀 수 있음 - 2부터 100만까지의 제곱수를 키로 하여 에라토스테네스를 돌리는 것
// 이를 위해 min~max 범위에서 제곱 ㄴㄴ 수인지 표시하는 배열을 만든다 - 범위가 배열로 충분히 만들 수 있음
// 이후 구하려는 제곱수가 max를 넘어서지 않는 선에서 변형 에라토스테네스를 돌려준다
// - 우선 해당 제곱수를 곱해 min 이상이 되게 만드는 값 p를 구한다 - 이 p를 1씩 올려주며 발견한 p * idx * idx는 곧 idx * idx로 나누어떨어지는 수
// - 그렇게 p를 1씩 올려주며 체크되지 않은 p * idx * idx를 지워둔다
// 이렇게 돌린 후 지워지지 않은 수를 세주면 완료