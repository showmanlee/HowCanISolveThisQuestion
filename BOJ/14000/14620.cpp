// 꽃밭
// https://www.acmicpc.net/problem/14620

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, res;
int board[11][11];
bool checked[11][11];

void dfs(int p, int sum) {
	if (p == 3) {
		res = min(res, sum);
		return;
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			bool place = true;
			for (int x = -1; x <= 1; x++) {
				for (int y = -1; y <= 1; y++) {
					if (x == 0 || y == 0)
						if (checked[i + x][j + y])
							place = false;
				}
			}
			if (!place)
				continue;
			int add = 0;
			for (int x = -1; x <= 1; x++) {
				for (int y = -1; y <= 1; y++) {
					if (x == 0 || y == 0) {
						checked[i + x][j + y] = true;
						add += board[i + x][j + y];
					}
				}
			}
			dfs(p + 1, sum + add);
			for (int x = -1; x <= 1; x++) {
				for (int y = -1; y <= 1; y++) {
					if (x == 0 || y == 0) {
						checked[i + x][j + y] = false;
					}
				}
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	res = 987654321;
	dfs(0, 0);
	cout << res << '\n';
}

// 씨앗을 심으면 상하좌우로 한 칸씩 꽃잎이 나는 꽃을 3개 심기 위해 꽃 하나 당 씨앗을 심을 위치와 상하좌우 한 칸씩 5칸의 땅을 사려고 할 때, 최소 비용은?

// 꽃잎이 서로 맞닿으면 꽃이 죽어버림 - 그렇다고 예제만 보고 3*3 전체를 안전구역으로 삼으면 안됨(1, 2 간격으로 떨어진 경우는?)
// 그리고 땅을 사야될 곳은 5칸씩 총 15칸임에 주의 - 씨앗을 심을 위치만 보는 것이 아님

// 결국 이 문제도 브포 - 보드의 크기가 최대 10*10이니 충분히 가능
// 상하좌우 한칸씩을 탐색하는 것은 dx/dy 배열로도 가능하지만, 여기서는 3*3 반복문을 돌리면서 좌표 이동값 중 하나 이상이 0인 경우에만 탐색
// 이러한 탐색을 땅 선택마다 3번 사용 - 지금 심으려는 곳이 유효한지 확인, 심기, 뽑기
// 땅을 심기 위해 선택한 땅 배열을 체크하면서 그렇게 선택한 땅들의 총 비용을 계산하여 다음 dfs 함수 호출의 매개 변수로 보내기
// 그렇게 3개를 심으면 지금까지 모인 합을 이용해 결과값을 갱신하고, 최종 결과 출력하기