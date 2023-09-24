// 변형 체스 놀이 : 다바바(Dabbaba)
// https://www.acmicpc.net/problem/29721

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int dx[4] = {2, 0, -2, 0};
int dy[4] = {0, 2, 0, -2};
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	map<pr, bool> place;
	vector<pr> places;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		pr p = {x, y};
		place[p] = true;
		places.push_back(p);
	}
	int res = 0;
	for (pr p : places) {
		for (int i = 0; i < 4; i++) {
			int xx = p.first + dx[i];
			int yy = p.second + dy[i];
			if (xx < 1 || yy < 1 || xx > n || yy > n) {
				continue;
			}
			pr pp = {xx, yy};
			if (!place[pp]) {
				place[pp] = true;
				res++;
			}
		}
	}
	cout << res << '\n';
}

// n*n 보드에 상하좌우로 2칸 움직일 수 있는 말이 k개 있을 때, 첫 턴의 움직임으로 새로 이동할 수 있는 위치의 개수 구하기

// 다른 말이 이미지 있지 않고 밖으로 벗어나지 않는 칸들을 찾아봅시다
// 다만 보드 크기가 10만*10만이라 2차원 배열로 하면 안 됨 - map으로 필요한 칸만 켤 수 있도록