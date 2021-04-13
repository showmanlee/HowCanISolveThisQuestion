// 영우는 사기꾼?
// https://www.acmicpc.net/problem/14676

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> tree(n + 1);
	vector<int> dim(n + 1);
	vector<pr> dialog(k);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		dim[b]++;
	}
	for (int i = 0; i < k; i++)
		cin >> dialog[i].first >> dialog[i].second;
	bool res = true;
	vector<int> build(n + 1);
	for (int i = 0; i < k; i++) {
		int b = dialog[i].second;
		if (dialog[i].first == 1) {
			if (dim[b] != 0) {
				res = false;
				break;
			}
			build[b]++;
			if (build[b] == 1) {
				for (int j : tree[b]) {
					dim[j]--;
				}
			}
		}
		else {
			build[b]--;
			if (build[b] < 0) {
				res = false;
				break;
			}
			else if (build[b] == 0) {
				for (int j : tree[b]) {
					dim[j]++;
				}
			}
		}
	}
	cout << (res ? "King-God-Emperor" : "Lier!") << '\n';
}

// 건설 트리가 있는 RTS 게임에서 건물 건설/파괴 현황이 주어졌을 때, 해당 플레이가 정상적인 플레이인지 판정하기
// 테크트리가 나오면 대부분 위상정렬
// 건설 관계가 주어지면 현재 건물을 지어서 만들 수 있는 건물들을 저장하는 2차원 vector(tree)에 정보를 넣고, 현재 건물을 짓기 위해 필요한 건물의 수를 저장하는 배열(dim)에 값을 추가
// 여기서 정상적인 플레이가 아닌 경우는 두 가지 - 건설 요건이 충족되지 않았지만 건물을 지으려는 경우, 건물이 없는데 건물을 파괴하려는 경우
// 같은 건물을 여러 개 지을 수 있으므로 현재 건물이 처음으로 지어지면 dim을 줄여주고, 마지막 건물이 파괴되면 dim을 다시 올려준다
// 내 상위 건물이 파괴되어도 내 건물은 일단 유지됨 - 그러나 그 상태에서 내 건물을 하나 더 지으려고 하면 에러