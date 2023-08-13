// 공항
// https://www.acmicpc.net/problem/10775

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int g, p;
int group[100001];
int finding(int p) {
	if (p == group[p])
		return p;
	return group[p] = finding(group[p]);
}

void unioning(int a, int b) {
	int ga = finding(a);
	int gb = finding(b);
	if (ga > gb)
		group[ga] = gb;
	else if (gb > ga)
		group[gb] = ga;

}

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	cin >> g >> p;
	for (int i = 1; i <= g; i++) {
		group[i] = i;
	}
	int res = 0;
	bool end = false;
	for (int i = 0; i < p; i++) {
		int t;
		cin >> t;
		if (end) {
			continue;
		}
		int tt = finding(t);
		if (tt == 0) {
			end = true;
			continue;
		}
		unioning(tt, tt - 1);
		res++;
	}
	cout << res << '\n';
}

// G개의 게이트가 있는 공항에 P개의 비행기가 도착하변서 1~t 게이트에 도킹하길 원하는 상황에서 어떤 비행기가 도킹할 게이트를 찾지 못했을 때 공항이 폐쇄된다고 할 때, 폐쇄되기 전 착륙할 수 있는 비행기의 수 구하기

// 정답은 각 비행기마다 가능한 가장 큰 게이트게 도킹하는 것 - 다만 이걸 구하려면 10만을 n^2로 찾아야 함
// 따라서 n^2가 아닌 방법으로 가장 가까운 곳을 찾아줘야 함 - 그 번호를 선택했을 때 갈 수 있는 가장 작은 번호를 union-find로 찾아준다
// 그렇게 어느 순간 못 가는 비행기가 발생하면 입력만 받고 처리는 하지 않는다 - 더 큰 번호를 선택해 들어갈 수 있는 상황에서도 불가능한 케이스가 앞에서 발생하면 들어올 수 없음