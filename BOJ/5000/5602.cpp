// 問題1
// https://www.acmicpc.net/problem/5602

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> score(m + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			int p;
			cin >> p;
			score[j] += p;
		}
	}
	vector<pr> sorter;
	for (int i = 1; i <= m; i++) {
		sorter.push_back({ score[i], i });
	}
	sort(sorter.begin(), sorter.end(), [](pr a, pr b) { if (a.first == b.first) return a.second < b.second; return a.first > b.first; });
	for (pr p : sorter) {
		cout << p.second << ' ';
	}
	cout << '\n';
}

// n명이 학생이 선택한 m개의 여행지의 선호 현황이 주어졌을 때, 득표수 내림차순 -> 번호 오름차순 순서대로 여행지 정렬하기

// 1차원 int 배열로 득표수를 집계한 후, 이 정보들을 pair 배열로 만들어서 기준에 맞게 정렬해서 출력하기 