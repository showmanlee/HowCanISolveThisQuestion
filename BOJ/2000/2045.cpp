// 마방진
// https://www.acmicpc.net/problem/2045

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(9);
	for (int i = 0; i < 9; i++) {
		cin >> v[i];
	}
	int key = 0;
	for (int i = 0; i < 3; i++) {
		if (v[i * 3] != 0 && v[i * 3 + 1] != 0 && v[i * 3 + 2] != 0) {
			key = v[i * 3] + v[i * 3 + 1] + v[i * 3 + 2];
		}
		if (v[i] != 0 && v[3 + i] != 0 && v[6 + i] != 0) {
			key = v[i] + v[3 + i] + v[6 + i]; 
		}
	}
	if (v[0] != 0 && v[4] != 0 && v[8] != 0) {
		key = v[0] + v[4] + v[8];
	}
	if (v[2] != 0 && v[4] != 0 && v[6] != 0) {
		key = v[2] + v[4] + v[6];
	}
	if (key == 0) {
		for (int i = 0; i < 9; i++) {
			key += v[i];
		}
		key /= 2;
	}
	for (int i = 0; i < 3; i++) {
		int cnt = 0;
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += v[i * 3 + j];
			if (v[i * 3 + j] == 0) {
				cnt++;
			}
		}
		if (cnt == 1) {
			for (int j = 0; j < 3; j++) {
				if (v[i * 3 + j] == 0) {
					v[i * 3 + j] = key - sum;
				}
			}
		}
		cnt = sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += v[j * 3 + i];
			if (v[j * 3 + i] == 0) {
				cnt++;
			}
		}
		if (cnt == 1) {
			for (int j = 0; j < 3; j++) {
				if (v[j * 3 + i] == 0) {
					v[j * 3 + i] = key - sum;
				}
			}
		}
	}
	if (v[0] == 0 && v[4] != 0 && v[8] != 0) {
		v[0] = key - v[4] - v[8];
	}
	if (v[0] != 0 && v[4] == 0 && v[8] != 0) {
		v[4] = key - v[0] - v[8];
	}
	if (v[0] != 0 && v[4] != 0 && v[8] == 0) {
		v[8] = key - v[4] - v[0];
	}
	if (v[2] == 0 && v[4] != 0 && v[6] != 0) {
		v[2] = key - v[4] - v[6];
	}
	if (v[2] != 0 && v[4] == 0 && v[6] != 0) {
		v[4] = key - v[2] - v[6];
	}
	if (v[2] != 0 && v[4] != 0 && v[6] == 0) {
		v[6] = key - v[4] - v[2];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << v[i * 3 + j] << ' ';
		}
		cout << '\n';
	}
}

// 3*3 마방진에 3개 이하의 빈칸이 생겼을 때, 빈칸 채우기

// 구멍이 3개 이하이기 때문에 대부분의 상황에서 한 줄이 모두 채워짐 - 이를 이용해 마방진의 기준 합을 구한다
// 하지만 구멍이 대각선으로 뚫려있다면 한 줄이 채워진 경우가 없음 - 이 경우 마방진 각 줄의 합이 모든 수의 합 / 3임을 이용, 채워진 6개의 합 / 2로 합을 구한다
// 이 합을 이용해 구멍이 하나인 줄에 채워넣으면 됨 - 두 개 이상이 뚫려 못 넣는 경우는 없음