// 십자카드 문제
// https://www.acmicpc.net/problem/2659

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v;
	for (int a = 1; a <= 9; a++) {
		for (int b = 1; b <= 9; b++) {
			for (int c = 1; c <= 9; c++) {
				for (int d = 1; d <= 9; d++) {
					int p = min(min(min(a * 1000 + b * 100 + c * 10 + d, b * 1000 + c * 100 + d * 10 + a), c * 1000 + d * 100 + a * 10 + b), d * 1000 + a * 100 + b * 10 + c);
					v.push_back(p);
				}
			}
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int p = min(min(min(a * 1000 + b * 100 + c * 10 + d, b * 1000 + c * 100 + d * 10 + a), c * 1000 + d * 100 + a * 10 + b), d * 1000 + a * 100 + b * 10 + c);
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == p) {
			cout << (i + 1) << '\n';
		}
	}
}

// 주어진 숫자가 시계방향으로 적힌 십자 카드가 주어질 때, 십자 카드 숫자를 시계방향으로 떼서 만든 가장 작은 수인 시계수가 몇 번째로 작은 시계수인지 판정하기

// 카드에는 1~9만 들어갈 수 있고, 카드에서 나올 수 있는 시계수는 만들 수 있는 가장 작은 수 하나 뿐
// 이를 이용해 모든 시계수 경우의 수를 구하고, 이를 중복 제거하여 정렬해둔다
// 이후 숫자를 받고 시계수로 만들어 몇 번째로 있는지 확인한다