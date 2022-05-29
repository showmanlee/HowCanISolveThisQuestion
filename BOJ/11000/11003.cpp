// 최솟값 찾기
// https://www.acmicpc.net/problem/11003

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, l;
	cin >> n >> l;
	priority_queue<pr> pq;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		pq.push({-p, i});
		while(!pq.empty()) {
			if (pq.top().second <= i - l) {
				pq.pop();
			} else {
				break;
			}
		}
		cout << -pq.top().first << ' ';
	}
	cout << '\n';
}

// 주어진 수열과 왼쪽으로 뻗는 범위의 길이가 주어질 때, 각 인덱스에서 출발하는 범위 안의 수 중 가장 작은 값 구하기

// 배열의 길이는 5백만 - 탐색 자체는 최대한 n으로 끝내야 함(투 포인터를 쓰기는 어려울듯)
// 힙을 이용해보자 - 힙 안에는 수와 그 수가 나온 인덱스를 저장
// 매 턴마다 수를 넣고 힙 안을 보며 힙 top에 있는 수가 현재 범위에서 벗어났다면 빼는 과정을 반복, 과정이 끝난 후 top의 수를 출력한다

// 오랜만의 플레 문제입니다