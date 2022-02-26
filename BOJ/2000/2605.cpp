// 줄 세우기
// https://www.acmicpc.net/problem/2605

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		res.insert(res.begin() + (i - p - 1), i);
	}
	for (int i : res) {
		cout << i << ' ';
	}
	cout << '\n';
}

// i번째 사람이 p번 카드를 뽑았을 때 세워진 줄에서 뒤에서부터 p자리 앞에 설 수 있을 때, 줄 선 결과 구하기

// 미리 세워진 줄 사이를 비집고 들어가야 한다는 의미 - 중간 삽입 필요
// 다행히 vector에는 insert를 통해 중간 자리에 원소를 넣을 수 있고, 인덱스는 (줄설 인원 수 - 카드 - 1)로 계산하면 된다