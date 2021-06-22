// 안녕
// https://www.acmicpc.net/problem/1535

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> lose(n), gain(n);
	for (int i = 0; i < n; i++)
		cin >> lose[i];
	for (int i = 0; i < n; i++)
		cin >> gain[i];
	int res = 0;
	int target = 1 << n;
	for (int t = 0; t < target; t++) {
		int health = 100, happy = 0;
		for (int i = 0; i < n; i++) {
			if ((t >> i) % 2 == 1) {
				health -= lose[i];
				happy += gain[i];
			}
		}
		if (health > 0)
			res = max(res, happy);
	}
	cout << res << '\n';
}

// 체력이 100인 사람이 다른 사람에게 인사를 할 때 체력을 소모하면서 기쁨을 얻을 때, 죽지 않으면서 얻을 수 있는 기쁨의 최대는?

// 사람 수가 20이니 브루트포스로도 접근 가능 - 2^n을 반복문으로 돌리는 비트마스크 방식으로 접근
// 메 케이스마다 선택된 사람에 대해 체력을 빼고 기쁨을 추가한 후, 체력이 0 이하로 떨어지지 않았다면 얻은 기쁨을 결과값에 갱신한다
// 이렇게 얻은 결과값을 출력