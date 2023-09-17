// 🍎📦 '사과상자'에 들어있는 것은 무엇? 현금?
// https://www.acmicpc.net/problem/29724

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int gram = 0, price = 0;
	for (int i = 0; i < n; i++) {
		char t;
		int w, h, l;
		cin >> t >> w >> h >> l;
		if (t == 'A') {
			int cnt = (w / 12) * (h / 12) * (l / 12);
			gram += 1000 + (500 * cnt);
			price += 4000 * cnt;
		} else if (t == 'B') {
			gram += 6000;
		}
	}
	cout << gram << '\n' << price << '\n';
}

// 1개에 4,000원씩 하는 12*12*12 크기의 500g 사과(w/ 1,000g 상자) 또는 무조건 한 박스에 50개씩 들어가는 120g 배즙이 있고 각각 크기가 다른 상자에 들어가있을 때, 상자들의 무게 총 합과 사과의 전체 가격 구하기

// 배는 무조건 6000g 넣어주면 되고, 사과는 갯수 구한 후 무게 및 가격 구해서 누적