// 배수 찾기
// https://www.acmicpc.net/problem/4994

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	while (true) {
		long long n;
		cin >> n;
		if (n == 0) {
			break;
		}
		queue<long long> q;
		q.push(1);
		while (!q.empty()) {
			long long p = q.front();
			q.pop();
			if (p % n == 0) {
				cout << p << '\n';
				break;
			}
			q.push(p * 10);
			q.push(p * 10 + 1);
		}
	}
}

// n의 배수면서 0과 1로만 구성된 수 찾기

// 배수를 먼저 찾지 말고 0과 1로 된 수를 만든 뒤 그게 배수인지 판정하자 - bfs 문제라는 뜻
// 1부터 *10, *10+1로 올라가며 찾아봅시다 - long long 범위 안에서 해결 가능해요