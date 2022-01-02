// Hello World!
// https://www.acmicpc.net/problem/13140

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nums[7];
bool shown[10];
bool found;
int n;

void dfs(int p) {
	if (found)
		return;
	if (p == 7) {
		int a = nums[2] * 10000 + nums[1] * 1000 + nums[3] * 100 + nums[3] * 10 + nums[4];
		int b = nums[6] * 10000 + nums[4] * 1000 + nums[5] * 100 + nums[3] * 10 + nums[0];
		if (a + b == n) {
			found = true;
			cout << "  " << a << '\n';
			cout << "+ " << b << '\n';
			cout << "-------" << '\n';
			cout << (n / 100000 == 0 ? "  " : " ") << n << '\n';
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (found)
			return;
		if (shown[i])
			continue;
		if (i == 0 && (p == 2 || p == 6))
			continue;
		nums[p] = i;
		shown[i] = true;
		dfs(p + 1);
		shown[i] = false;
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	found = false;
	cin >> n;
	dfs(0);
	if (!found)
		cout << "No Answer\n";
}

// hello + world = n 꼴의 수식을 만족하는 서로 다른 숫자 d, e, h, l, o, r, w 구하기(h != 0, w != 0)
// 기본적으로 숫자 7개 자리를 골라야 하는 브포 - h, w 슬롯에 0이 들어가지 않게 처리
// 7개를 모두 고르면 고른 숫자대로 hello와 world를 만들어서 수식 확인, 수식이 성립하면 해당 수식 출력하기
// 수식이 구해지면 구했다는 표시를 하여, 이후 탐색을 하지 않도록 설정 - 만약 못 구했다면 No Answer를 출력할 수 있게도 설정