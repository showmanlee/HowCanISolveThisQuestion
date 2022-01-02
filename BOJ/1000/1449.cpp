// 수리공 항승
// https://www.acmicpc.net/problem/1449

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, l;
	cin >> n >> l;
	vector<int> holes(n);
	for (int i = 0; i < n; i++)
		cin >> holes[i];
	sort(holes.begin(), holes.end());
	int cur = holes[0];
	int res = 1;
	for (int i = 0; i < n; i++) {
		if (holes[i] - cur > l - 1) {
			cur = holes[i];
			res++;
		}
	}
	cout << res << '\n';
}

// 수많은 길이 l의 테이프로 특정 지점들에 있는 구멍들을 양옆 0.5의 공간을 두고 막으려 할 때, 필요한 테이프의 수는?

// 양옆 0.5의 공간을 두고 막으려고 한다 - 구멍(들)을 막을 때 구멍들의 위치의 차 + 1의 테이프가 필요하다
// 우선 점들의 위치를 모두 정렬하고, 첫 칸을 '테이프가 시작하는 위치'로 삼는다
// 이후 옆칸들을 순회하면서, 한 테이프로 옆 구멍들을 막을 수 있다면(현재 - 시작 > 길이 - 1) 계속 진행한다
// 만약 그렇지 않다면 '테이프가 시작하는 위치'를 해당 칸으로 잡고, 필요한 테이프 수를 하나 늘린다