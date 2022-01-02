// 중앙값 구하기
// https://www.acmicpc.net/problem/2696

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		priority_queue<int> maxh;
		priority_queue<int, vector<int>, greater<int>> minh;
		vector<int> res;
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			if (maxh.size() > minh.size())
				minh.push(p);
			else
				maxh.push(p);
			if (maxh.size() != 0 && minh.size() != 0) {
				if (maxh.top() > minh.top()) {
					int a = maxh.top();
					int b = minh.top();
					maxh.pop();
					minh.pop();
					maxh.push(b);
					minh.push(a);
				}
			}
			if (i % 2 == 0)
				res.push_back(maxh.top());
		}
		cout << res.size() << '\n';
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << ' ';
			if (i % 10 == 9)
				cout << '\n';
		}
	}
}

// 수열의 수를 순회하면서 홀수 번째 수를 읽을 때 현재까지 읽은 수의 중앙값 출력하기
// 수가 들어올 때마다 정렬하기에는 부담이 큼 - 두 개의 힙을 이용한 중앙값 구하기를 사용

// 최소 힙과 최대 힙을 만들고, 수를 받을 때 최소 힙의 최대 힙보다 작으면 최소 힙, 그렇지 않다면 최대 힙에 삽입
// 이후 최소 힙의 top보다 최대 힙의 top이 더 커진 경우 두 힙의 top을 서로 교환
// 그 결과 최대 힙의 top이 중앙값이 됨 - 이렇게 얻은 중앙값을 결과 배열에 넣고, 순회 종료 후 순서대로 출력하기

// 입력과 출력이 10개 단위로 들어오고, 나와야 함에 주의