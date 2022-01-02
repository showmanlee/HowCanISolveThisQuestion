// 치킨 쿠폰
// https://www.acmicpc.net/problem/1673

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	while (cin >> n) {
		cin >> k;
		int res = 0, cop = n, stamp = 0;
		while (cop != 0) {
			res += cop;
			stamp += cop;
			cop = stamp / k;
			stamp %= k;
		}
		cout << res << '\n';
	}
}

// 치킨을 한 마리 주문하는데 사용하는 쿠폰이 n장 있고, 한 마리당 찍히는 도장 k개를 모아 쿠폰 하나로 바꿀 수 있을 때, 주어진 쿠폰으로 살 수 있는 치킨의 총합은?

// 기본적으로 쿠폰이 사라질 때까지 while문 안에서 계속 치킨을 주문해야 함
// 단순히 쿠폰 개수만으로 뒤적거릴 수는 없음 - 계산을 반복하면서 남은 도장이 쌓이면 그것도 쿠폰이 되기 때문
// 따라서 쿠폰과 도장의 수를 별개로 계산해야 함 - 쿠폰이 0개가 될 때까지
// 처음에는 쿠폰 수는 n개, 도장 수는 0개로 시작
// while문 안에서는 수중의 쿠폰 전체를 치킨으로 바꾸고, 그만큼의 도장을 얻는다
// 그리고 여기서 얻은 도장 수 / k의 몫은 추가 쿠폰의 수, 나머지는 남은 도장의 수
// 이렇게 쿠폰이 0개가 될 때까지 계속 돌린 후 결과를 출력한다