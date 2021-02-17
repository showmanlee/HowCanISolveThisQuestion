// 도영이가 만든 맛있는 음식
// https://www.acmicpc.net/problem/2961

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int, int> pr;

int diff = 1000000000;

void bf(vector<pr> v, int i, int n, int s, int b) {
	s *= v[i].first;
	b += v[i].second;
	if (abs(s - b) < diff) 
		diff = abs(s - b);
	for (int j = i + 1; j < n; j++)
		bf(v, j, n, s, b);
}

int main(void) {
	int n;
	cin >> n;
	vector<pr> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	for (int i = 0; i < n; i++) {
		bf(v, i, n, 1, 0);
	}
	cout << diff << '\n';
}

// 재료의 신맛은 넣을수록 곱해지고, 쓴맛은 넣을수록 더해질 때, 신맛과 쓴맛을 최소화하는 조합의 맛 간의 차는?
// 브루트포스 - DFS 활용하기