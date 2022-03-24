// 현대모비스와 함께하는 부품 관리
// https://www.acmicpc.net/problem/24724

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		int n, a, b;
		cin >> n >> a >> b;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
		}
		cout << "Material Management " << t << '\n';
		cout << "Classification ---- End!\n";
	}
}

// 각 부품의 무게와 크기가 주어질 때, 현대모비스에서 만들어준 부품 그룹 분류 프로그램을 이용해 각 그룹의 부품의 무게 합과 크기 합을 넘기지 않도록 그룹 분류하기

// 웃긴 사실 - 그룹 분류를 해야 하는데 그걸 현대모비스에서 만들어줌
// 따라서 우리가 이를 갖고 계산을 할 필요 없이, '현대모비스에서 만든 프로그램을 돌린 후 나오는 메시지'만 출력해주면 됨
// 물론 입력은 그만큼 넣어줘야 하지만, 그걸 별도로 저장해 계산할 필요가 없음