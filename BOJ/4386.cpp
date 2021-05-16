// 별자리 만들기
// https://www.acmicpc.net/problem/4386

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<double, double> pr;
typedef pair<double, pair<int, int>> prr;

int group[101];

int finding(int p) {
	if (group[p] == p)
		return p;
	return group[p] = finding(group[p]);
}

void unioning(int a, int b) {
	int ga = finding(a), gb = finding(b);
	if (ga > gb)
		group[ga] = gb;
	else
		group[gb] = ga;
}

int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pr> v(n);
	vector<prr> edges;
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			edges.push_back({ sqrt(pow(abs(v[i].first - v[j].first), 2) + pow(abs(v[i].second - v[j].second), 2)), {i, j} });
	sort(edges.begin(), edges.end());
	for (int i = 0; i < n; i++)
		group[i] = i;
	int cnt = 0;
	double res = 0;
	for (prr e : edges) {
		double l = e.first;
		int a = e.second.first;
		int b = e.second.second;
		if (finding(a) != finding(b)) {
			unioning(a, b);
			cnt++;
			res += l;
		}
		if (cnt == n - 1)
			break;
	}
	printf("%.2f\n", res);
}

// 2차원 공간에 별들이 있을 때, 별들을 모두 이어 별자리를 만드는데 드는 최소 비용은?
// 이런 상황에서의 최소 비용은 MST - 따라서 이 문제는 2차원 공간 상의 점들에 대한 MST 문제
// MST를 구해야 하는 그래프를 모든 점이 이어진 완전 그래프라고 가정하고, 점의 좌표를 받으면 모든 점들간의 거리를 저장하고, 정렬해서, 크루스칼 돌리기
// 입력과 결과가 실수형으로 주어짐 - 출력은 printf로 처리하기