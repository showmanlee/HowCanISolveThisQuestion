// 회전 초밥
// https://www.acmicpc.net/problem/15961

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, d, k, c;
	cin >> n >> d >> k >> c;
	vector<int> sushi(n + 1);
	for (int i = 0; i < n; i++)
		cin >> sushi[i];
	vector<int> count(d + 1);
	deque<int> roster;
	int res = 0, cnt = 0;
	for (int i = 0; i < k; i++) {
		roster.push_back(sushi[i]);
		count[sushi[i]]++;
		if (count[sushi[i]] == 1)
			cnt++;
		res = max((count[c] == 0 ? cnt + 1 : cnt), res);
	}
	for (int i = 0; i < n; i++) {
		roster.pop_front();
		count[sushi[i]]--;
		if (count[sushi[i]] == 0)
			cnt--;
		roster.push_back(sushi[(i + k) % n]);
		count[sushi[(i + k) % n]]++;
		if (count[sushi[(i + k) % n]] == 1)
			cnt++;
		res = max((count[c] == 0 ? cnt + 1 : cnt), res);
	}
	cout << res << '\n';
}

// d가지 종류의 초밥 n개가 단방향 원형으로 이어진 회전 초밥 벨트에서 연속으로 k개의 초밥을 먹으며 c번 초밥을 서비스로 먹을 때, 먹을 수 있는 초밥 가짓수의 최댓값은?

// n은 300만, 그러나 d와 k는 3000 - 당연히 가짓수 중복을 고려해야 하는 문제
// 하지만 당연히 각 범위별로 이중 for를 돌리면 시간초과 - 따라서 deque를 이용한 슬라이딩 윈도우 공법을 활용해야 함 
// deque를 이용해 앞과 뒤에서 초밥을 넣고 빼면서, 넣고 빼는 과정에서 초밥 종류별 소지 개수를 배열로 기록하면 모든 경우의 수를 n^2 없이도 알 수 있음

// 이 방법으로 문제를 풀기 위해 deque 하나와 현재 소지한 종류별 초밥 개수를 기록하는 카운터 배열, 그리고 해당 배열을 이용해 가지고 있는 종류의 수를 기록하는 변수를 준비
// 초밥들을 입력받은 후, 첫 k개의 초밥을 deque에 넣는다 - 넣는 과정에서 카운터 배열의 들어간 종류 칸을 ++하고, 해당 값이 1이 되면 소지 종류 수를 증가
// 초밥들을 모두 넣으면 쿠폰 초밥의 소지 여부를 확인, 소지하고 있다면 현재 소지 종류 수, 그렇지 않다면 거기에 +1을 결과값에 갱신
// 이후 모든 초밥을 순회하며 i번째 초밥을 빼고(pop_front), 그 자리에 (i + k) % n번째를 붙인다 - 초밥을 빼면서 아까와 반대로 카운터 배열의 값을 1 줄이고, 해당 값이 0이 되면 소지 종류 수 감소
// 이렇게 모든 초밥 범위 윈도우를 순회한 후, 나온 종류값들 중 최댓값이 정답