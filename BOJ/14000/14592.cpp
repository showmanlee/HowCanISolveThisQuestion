// 2017 아주대학교 프로그래밍 경시대회 (Small)
// https://www.acmicpc.net/problem/14592

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct candi {
	int s, c, l, p;
};

bool compare(candi a, candi b) {
	if (a.s != b.s)
		return a.s > b.s;
	if (a.c != b.c)
		return a.c < b.c;
	return a.l < b.l;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<candi> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].s >> v[i].c >> v[i].l;
		v[i].p = i + 1;
	}
	stable_sort(v.begin(), v.end(), compare);
	cout << v[0].p << '\n';
}

// 프로그래밍 경시대회 참가자들을 문제 점수 내림차순 -> 제출 횟수 오름차순 -> 업로드 시간 오름차순으로 정렬한 후 첫 번째로 위치하는 참가자 번호 출력하기

// 정렬 우선순위 정해서 정렬 후 출력하기 - 만약을 위해 병합 정렬 기반의 stable_sort로 정렬
// Small은 참가자 수가 최대 3명이지만, 10000명까지 나오는 Large에 대비하여 정렬 함수 돌리기