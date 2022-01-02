// 카드2
// https://www.acmicpc.net/problem/2164

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		q.push(i);
	while (q.size() > 1) {
		q.pop();
		int t = q.front();
		q.pop();
		q.push(t);
	}
	cout << q.front() << '\n';
}

// queue 클래스가 없다면 동적 리스트로 처리해도 될듯
// 배열은 넣고 빼는 과정이 복잡할 거 같아