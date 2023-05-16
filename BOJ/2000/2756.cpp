// 다트
// https://www.acmicpc.net/problem/2756

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<float, float> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		vector<vector<pr>> pos(2, vector<pr>(3));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> pos[i][j].first >> pos[i][j].second;
			}
		}
		vector<int> score(2);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				float dist = sqrt(pow(pos[i][j].first, 2) + pow(pos[i][j].second, 2));
				if (dist <= 3.0f) {
					score[i] += 100;
				} else if (dist <= 6.0f) {
					score[i] += 80;
				} else if (dist <= 9.0f) {
					score[i] += 60;
				} else if (dist <= 12.0f) {
					score[i] += 40;
				} else if (dist <= 15.0f) {
					score[i] += 20;
				} 
			}
		}
		cout << "SCORE: " << score[0] << " to " << score[1] << ", " << (score[0] == score[1] ? "TIE." : score[0] > score[1] ? "PLAYER 1 WINS." : "PLAYER 2 WINS.") << '\n';
	}
}

// 중앙에서 3-6-9-12-15cm 안쪽에 맞출 때 각각 100-80-60-40-20점을 얻을 수 있는 다트를 각각 3발씩 던진 좌표가 주어질 때, 승자 구하기

// 중앙과의 거리를 구한 후 더해서 계산해준다