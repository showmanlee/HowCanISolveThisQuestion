// 패턴
// https://www.acmicpc.net/problem/17300

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> pattern(n);
	for (int i = 0; i < n; i++)
		cin >> pattern[i];
	vector<bool> visit(10);
	visit[pattern[0]] = true;
	int fail = false;
	for (int i = 1; i < n; i++) {
		if (visit[pattern[i]])
			fail = true;
		for (int j = 0; j < 3; j++) {
			if ((pattern[i] == j * 3 + 1 && pattern[i - 1] == j * 3 + 3) || (pattern[i] == j * 3 + 3 && pattern[i - 1] == j * 3 + 1)) {
				if (!visit[j * 3 + 2])
					fail = true;
			}
			if ((pattern[i] == j + 1 && pattern[i - 1] == j + 7) || (pattern[i] == j + 7 && pattern[i - 1] == j + 1)) {
				if (!visit[j + 4])
					fail = true;
			}
		}
		if ((pattern[i] == 1 && pattern[i - 1] == 9) || (pattern[i] == 9 && pattern[i - 1] == 1) || (pattern[i] == 3 && pattern[i - 1] == 7) || (pattern[i] == 7 && pattern[i - 1] == 3)) {
			if (!visit[5])
				fail = true;
		}
		if (fail)
			break;
		visit[pattern[i]] = true;
	}

	cout << (fail ? "NO" : "YES") << '\n';
}

// 안드로이드 잠금패턴에서 경로가 주어졌을 때, 유효한 경로인지 판정하기

// 문제에서 주어진 제약조건은 다음과 같다
// * 패턴의 길이는 3 이상이다. - 입력 길이 자체가 3 이상이라 체크할 필요 없음
// * 패턴을 나타내는 수열에는 같은 점이 두번 이상 등장하지 않는다. - 중복하여 등장할 수 있기에 판정 필요
// * 수열의 인접한 점을 연결해 만든 선분 위에는 아직 등장하지 않은 점이 있을 수 없다. - 이번 문제의 주요 파트

// 우선 2번 조건을 확인하기 위해 방문한 점은 visit 배열에 체크해주기
// 3번 조건에 위배되는 상황은 가로/세로/대각선으로 두 칸 이동했는데, 그 사이에 있는 점을 방문하지 않은 경우
// 즉, 1-3, 4-6, 7-9, 1-7, 2-8, 3-9, 1-9, 3-7과 이 케이스들의 역에서 중간점이 없다면 아웃
// 따라서 이러한 상황들이 발견된 경우 실패 판정하기