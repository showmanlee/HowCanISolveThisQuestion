// 올림픽
// https://www.acmicpc.net/problem/8979

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct status {
	int code, gold, silver, bronze;
};

bool sorter(status& a, status& b) {
	if (a.gold == b.gold) {
		if (a.silver == b.silver) 
			return a.bronze > b.bronze;
		return a.silver > b.silver;
	}
	return a.gold > b.gold;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<status> order(n);
	int gg, gs, gb;
	for (int i = 0; i < n; i++) {
		int p, g, s, b;
		cin >> p >> g >> s >> b;
		order[i] = { p, g, s, b };
		if (p == k) {
			gg = g;
			gs = s;
			gb = b;
		}
	}
	sort(order.begin(), order.end(), sorter);
	for (int i = 0; i < n; i++) {
		if (order[i].gold == gg && order[i].silver == gs && order[i].bronze == gb) {
			cout << (i + 1) << '\n';
			break;
		}
	}
}

// 금-은-동 순으로 메달 순위가 매겨진다 -  국가 번호를 포함한 결과표가 주어질 때, 어떤 국가의 최종 순위를 구하라

// 금-은-동 순으로 내림차순 정렬하는 정렬 함수를 sort에 적용해 정렬하기 - 결과 자료구조는 금-은-동과 더불어 해당 국가의 번호도 기록한다
// 다만 여기서 공동 순위가 존재함에 주의 - 메달 개수가 모두 동일하면 모두 상위 등수를 가지게 되고, 하위 등수는 소멸된다(1-2-2-4)
// 따라서 찾으려는 국가가 공동 순위(인덱스) 내에 있을 경우, 해당 공동 순위의 맨 앞 등수(인덱스)를 출력해야 한다
// 이를 위해 정렬된 배열에서 국가를 찾을 때 국가 번호 대신 금-은-동 메달 개수로 찾을 수 있음 - 처음 입력받을 때 해당 국가가 입력되면 그 국가의 금-은-동 개수를 따로 빼둔다
// 그렇게 찾아지는 등수는 반드시 공동 순위가 되고, 그것이 답