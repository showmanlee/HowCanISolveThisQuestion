// N번째 큰 수
// https://www.acmicpc.net/problem/2075

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n * n; i++) {
		int p;
		cin >> p;
		if (pq.size() < n) {
			pq.push(-p);
		}
		else {
			if (-pq.top() < p) {
				pq.pop();
				pq.push(-p);
			}
		}
	}
	cout << -pq.top() << '\n';
}

// 자신 한 칸 위의 수보다 크다는 규칙으로 n*n 보드에 채워진	정수 중 n번째로 큰 수 구하기

// 채워진 규칙은 의미없음 - 전체에서 n번째 큰 수를 뽑는 거니
// 메모리 제한이 빡빡하게 걸려있고, n이 1500까지 주어질 수 있으니 정렬 문제는 아님
// 힙 문제 - 최대 n개의 수가 들어갈 수 있는 최소 힙을 이용해 답을 구한다
// 수를 넣되, 힙이 가득 찬 상태에서 top 값이 현재 수보다 작다면 top을 빼고 현재 수를 넣어준다
// 이 과정을 반복한 뒤 힙 top에 있는 수가 답