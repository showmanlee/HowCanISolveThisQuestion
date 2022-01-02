// Yonsei TOTO
// https://www.acmicpc.net/problem/12018

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> need(n);
	for (int i = 0; i < n; i++) {
		int p, l;
		cin >> p >> l;
		vector<int> enlist(p);
		for (int j = 0; j < p; j++)
			cin >> enlist[j];
		if (p < l) {
			need[i] = 1;
			continue;
		}
		sort(enlist.begin(), enlist.end(), greater<int>());
		need[i] = enlist[l - 1];
	}
	sort(need.begin(), need.end());
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (need[i] <= m) {
			m -= need[i];
			res++;
		}
		else
			break;
	}
	cout << res << '\n';
}

// 마일리지 제도로 운영되고 있는 수강신청 시스템에서 각 과목에 수강신청한 사람들과 그들이 넣은 마일리지를 알 수 있을 때, 현재 가지고 있는 마일리지로 확보할 수 있는 과목의 최대 수는?
// 각 과목은 수강 인원 제한, 그리고 수강한 사람들(이 낸 마일리지)가 존재한다
// 만약 수강 인원 제한보다 적은 인원이 신청한 경우에는 최소 마일리지(1)만 내면 수강 가능
// 그렇지 않은 경우 마일리지들을 내림차순으로 정렬해 수강 인원 제한(l) 번째 마일리지를 내면 수강 가능 - 마일리지가 동률일 때 내가 우선
// 이렇게 산정한 마일리지 지급액을 오름차순으로 정렬해, 마일리지가 떨어질 때까지 지불하면 신청한 과목 수가 결과가 됨