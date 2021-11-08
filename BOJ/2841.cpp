// 외계인의 기타 연주
// https://www.acmicpc.net/problem/2841

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
 
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, p;
	cin >> n >> p;
	vector<stack<int>> st(7);
	int res = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (st[a].empty() || st[a].top() < b) {
			st[a].push(b);
			res++;
		}
		else if (st[a].top() > b) {
			while (!st[a].empty()) {
				if (st[a].top() <= b) {
					if (st[a].top() < b) {
						st[a].push(b);
						res++;
					}
					break;
				}
				st[a].pop();
				res++;
			}
			if (st[a].empty()) {
				st[a].push(b);
				res++;
			}
		}
	}
	cout << res << '\n';
}

// 수십억 개의 손가락을 가진 외계인이 프렛 p개의 6현 기타의 멜로디를 순서대로 칠 때, 손가락을 떼거나 누르는 최소 횟수는?

// 현재 잡고 있는 프렛보다 높은 프렛을 잡을 때는 누르고 있는 손가락을 유지한 채로 새로 누르고, 낮은 프렛을 잡을 때는 해당 프렛보다 높은 프렛을 모두 뗀다
// 손가락은 무한하고 줄은 언제나 6개이기에 6개의 스택을 이용하여 문제를 풀 수 있음
// 스택은 항상 오름차순으로 쌓이게 두고, 스택에서 들어오고 나올 때마다 횟수를 하나씩 늘린다
// 만약 스택이 비어있거나 top이 현재 숫자보다 높으면 그냥 넣고, 그렇지 않으면 조건이 충족될 때까지 스택에서 빼다가 넣는다