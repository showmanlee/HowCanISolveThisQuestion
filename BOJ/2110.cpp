// 공유기 설치
// https://www.acmicpc.net/problem/2110

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, c;
	cin >> n >> c;
	vector<int> houses(n);
	for (int i = 0; i < n; i++)
		cin >> houses[i];
	sort(houses.begin(), houses.end());
	int left = 1;
	int right = houses[n - 1] - houses[0];
	int res = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int beg = houses[0];
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (houses[i] - beg >= mid) {
				cnt++;
				beg = houses[i];
			}
		}
		if (cnt >= c) {
			res = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << res << '\n';
}

// 집의 위치와 공유기의 개수가 주어졌을 때, 공유기의 간격을 최대로 하는 경우의 수 찾기

// 직접 집을 고르거나, 간격을 선형으로 벌려나가는 것은 불가능(좌표가 최대 10억)
// 따라서 logN 풀이법을 도입해야 함 - 간격에 이분 탐색을 도입해보자
// 간격 최소는 1, 최대는 마지막 집 - 첫 집으로 설정하고 이분 탐색 시작
// 최대한 넓게 공유기를 뿌리려면 첫 번째 집에 공유기를 설치해야 함 - 따라서 설치 과정은 무조건 첫 집부터
// 첫 집부터 공유기를 설치해 다음 집들로 나아가면서, 선택한 집과 이전 공유기와의 거리가 현재 거리 이상이 되면 해당 지점에 공유기 설치
// 공유기 설치 시 개수를 더하고, 이전 공유기 위치를 해당 집으로 갱신 - 이렇게 마지막 집까지 반복
// 이렇게 설치한 공유기 개수가 c개 이상이 되면 left를 mid화하고, 그렇지 않으면 반대로 설정 - left를 mid화하면서 결과값도 갱신
// c개 이상의 공유기를 설치할 수 있으면 최소 c개는 설치할 수 있다는 것 - 반대로 c개 미만을 설치할 수 있을 경우 문제에서 원하는 답이 아님
// 그래서 최종적으로 나오는 결과값이 답