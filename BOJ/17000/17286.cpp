// 유미
// https://www.acmicpc.net/problem/17286

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<float, float> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> order = {0, 1, 2};
	pr start;
	cin >> start.first >> start.second;
	vector<pr> points(3);
	for (int i = 0; i < 3; i++) {
		cin >> points[i].first >> points[i].second;
	}
	float res = 987654321;
	do {
		pr coord = start;
		float sum = 0;
		for (int i = 0; i < 3; i++) {
			int x = points[order[i]].first - coord.first;
			int y = points[order[i]].second - coord.second;
			sum += sqrt((x * x) + (y * y));
			coord = points[order[i]];
		}
		res = min(res, sum);
	} while (next_permutation(order.begin(), order.end()));
	cout << int(res) << '\n';
}

// 2차원 좌표 내 유미의 위치와 세 사람의 위치가 주어졌을 때, 유미가 세 사람에게 모두 도달하는 최단거리(소수 버림) 구하기

// 어차피 3명이므로 순서 자체는 브루트포스로 구하면 됨
// 거리는 좌표평면이므로 sqrt로 쉽게 구할 수 있음 - 세 sqrt의 합을 소수 버리고 출력하기
