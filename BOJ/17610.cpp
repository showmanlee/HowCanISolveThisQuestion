// 양팔저울
// https://www.acmicpc.net/problem/17610

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int num[14];
bool visit[14][2600001];

void bf(int i, int r) {
	if (visit[i][r])
		return;
	visit[i][r] = true;
	if (i == n)
		return;
	bf(i + 1, r + num[i]);
	bf(i + 1, abs(r - num[i]));
	bf(i + 1, r);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		sum += num[i];
	}
	bf(0, 0);
	int res = 0;
	for (int i = 1; i <= sum; i++)
		if (!visit[n][i])
			res++;
	cout << res << '\n';
}

// 양팔 저울과 n개의 추를 한 번만 사용해 정확한 무게로 물을 채울 때, 1부터 추 무게의 합까지의 무게 중 잴 수 없는 무게의 수는?
// 물병이 없는 쪽에 추를 놓아 없는 쪽 무게의 합만큼의 물을 채울 수 있고, 물병이 있는 쪽에도 추를 놓아 (없는 쪽 - 있는 쪽)만큼의 물을 채울 수도 있다
// 따라서 추를 놓는 경우의 수는 세 가지 - 양 쪽에 놓거나, 아예 안 놓거나
// 추 하나당 무게는 최대 20만 - 최대 13개의 추가 주어지므로 최대 260만 - visit 배열로 충분히 관리 가능

// 브루트포스 재귀함수를 통해 추를 순서대로 하나씩 놓으며, 마지막 추를 놓았다면 재귀 호출을 멈춘다
// visit 배열은 현재까지 사용한 추의 개수와 잴 수 있는 무게를 동시에 추적할 수 있도록 2차원으로 선언 - 1차원으로만 선언하면 추의 개수가 다른 상황에서 같은 무게에 도달했을 때 새로운 경로를 찾을 수 없음
// 이후 추를 모두 사용한 상태의 visit를 1부터 모든 추 무게의 합까지 순회하며 체크되지 않은 개수를 세면 그게 결과가 됨
