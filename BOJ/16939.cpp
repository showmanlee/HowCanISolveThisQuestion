// 2×2×2 큐브
// https://www.acmicpc.net/problem/16939

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> cube(24);
	for (int i = 0; i < 24; i++)
		cin >> cube[i];

	vector<bool> same(6);
	for (int i = 0; i < 6; i++)
		same[i] = (cube[i * 4] == cube[i * 4 + 1] && cube[i * 4 + 1] == cube[i * 4 + 2] && cube[i * 4 + 2] == cube[i * 4 + 3]);
	int cnt = 0;
	for (int i = 0; i < 6; i++)
		if (same[i])
			cnt++;

	int rot = 0;
	if (cnt != 2) {
		cout << 0 << '\n';
		return 0;
	}
	if (same[3] && same[4])
		rot = 0;
	else if (same[0] && same[2])
		rot = 1;
	else if (same[1] && same[5])
		rot = 2;
	else {
		cout << 0 << '\n';
		return 0;
	}

	int res = 0;
	for (int t = 0; t < 3; t++) {
		if (rot == 0) {
			int t1 = cube[1];
			int t2 = cube[3];
			cube[1] = cube[5];
			cube[3] = cube[7];
			cube[5] = cube[9];
			cube[7] = cube[11];
			cube[9] = cube[20];
			cube[11] = cube[22];
			cube[20] = t1;
			cube[22] = t2;
		}
		else if (rot == 1) {
			int t1 = cube[14];
			int t2 = cube[15];
			cube[14] = cube[6];
			cube[15] = cube[7];
			cube[6] = cube[18];
			cube[7] = cube[19];
			cube[18] = cube[22];
			cube[19] = cube[23];
			cube[22] = t1;
			cube[23] = t2;

		}
		else if (rot == 2) {
			int t1 = cube[2];
			int t2 = cube[3];
			cube[2] = cube[15];
			cube[3] = cube[13];
			cube[15] = cube[9];
			cube[13] = cube[8];
			cube[9] = cube[16];
			cube[8] = cube[18];
			cube[16] = t1;
			cube[18] = t2;
		}
		if (t == 1)
			continue;
		bool flag = true;
		for (int i = 0; i < 6; i++) {
			flag = (cube[i * 4] == cube[i * 4 + 1] && cube[i * 4 + 1] == cube[i * 4 + 2] && cube[i * 4 + 2] == cube[i * 4 + 3]);
			if (!flag)
				break;
		}
		if (flag) {
			res = 1;
			break;
		}
	}
	cout << res << '\n';
	return 0;
}

// 주어진 2x2x2 루빅스 큐브가 단 한 번만 돌리면 풀리는 상태인가?

//       01 02 
//       03 04
// 13 14 05 06 17 18 21 22        ((n - 1) / 4)
// 15 16 07 08 19 20 23 24    ...     0
//       09 10                      3 1 4 5
//       11 12                        2
// 큐브는 위와 같은 전개도로 주어진다 - 육면체 전개도

// 일단 한 번에 돌려서 완성되려면 마주보는 면(0-2, 1-5, 3-4)을 구성하는 네 칸의 색상이 모두 동일해야 함 - 이거 먼저 체크
// 큐브가 모두 맞춰진 경우도 여기선 실패 판정임에 주의 - 정확히 두 면이, 그것도 마주보는 면만 동일해야 다음 과정으로 넘어갈 수 있음

// 돌리는 방향은 3가지 - 3-4를 축으로 회전, 0-2를 축으로 회전, 1-5를 축으로 회전 - 회전 방향은 네 칸의 색상이 동일한 두 면의 위치를 보고 판별
// 이 문제에서 '한 번' 돌리는 것은 90도 돌리는 것
// 따라서 180도 돌리는 것은 고려하면 안 되고, 270도 돌리는 것은 반대로 '한 번' 돌리는 것이기에 고려해야 함 - 회전은 세 번 진행하되, 판정은 두 번만 진행해야 함
// 한 축에서 회전할 수 있는 방법은 4가지 - 위쪽 정회전, 위쪽 역회전, 아래쪽 정회전, 아래쪽 역회전
// 여기서 역회전 = 정회전 3회로 치환 가능, 아래쪽 정/역회전 역시 결과적으로 위쪽 역/정회전과 같음
// 결과적으로 위쪽 정회전을 1/3회 하면 회전하는 모든 결과를 얻을 수 있음

// 회전 과정에서 swap해야 하는 위치 (실제 코드에서는 여기서 인덱스가 -1이 됨)
// 3-4를 축으로 회전할 경우: 02 04 - 06 08 - 10 12 - 23 21 (01 04 - 05 07 - 09 11 - 22 20)
// 0-2를 축으로 최전할 경우: 15 16 - 07 08 - 19 20 - 23 24 (14 15 - 06 07 - 18 19 - 22 23)
// 1-5를 축으로 회전할 경우: 03 04 - 16 14 - 10 09 - 17 19 (02 03 - 15 13 - 09 08 - 16 18)
// 돌린 결과 6개 모두가 맞는다면 성공, 그렇지 않으면 실패
