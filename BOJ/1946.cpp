// 신입 사원
// https://www.acmicpc.net/problem/1946

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		vector<pr> cands(n);
		for (int i = 0; i < n; i++)
			cin >> cands[i].first >> cands[i].second;
		sort(cands.begin(), cands.end());
		int res = 1;
		int comp = cands[0].second;
		for (int i = 1; i < n; i++) {
			if (cands[i].second < comp) {
				res++;
				comp = cands[i].second;
			}
		}
		cout << res << '\n';
	}
}

// 다른 사람들과 비교해 두 성적 모두가 떨어지지 않는 사람을 뽑는다고 할 때 최대로 뽑을 수 있는 사람의 수는?
// 주어지는 수가 점수가 아님에 주의 - 중복값이 나오지 않음
// 데이터 100000개가 들어오기 때문에 n^2로 풀 수는 없음

// 탈락되는 조건 = 다른 사람들 중 나보다 성적 2개가 모두 좋은 사람이 1명이라도 있다면 나가리
// 일단 pair로 두 순위를 받고 오름차순으로 정렬 - 기본 함수 사용시 첫 번째 순위로 정렬됨
// 첫 친구는 첫 순위의 최상위임을 보장하므로 무조건 통과, 그 다음 친구부터 접근 시작
// 다음 친구는 첫 친구보다 첫 순위가 낮다는 게 보장된 상황, 여기서 두 번째 순위까지 첫 친구보다 낮다면 탈락
// 이후 비교된 두 번째 순위들 중 가장 높은 값을 선택(통과한 사람의 순위를 선택), 그 순위값을 기준으로 위 과정 반복