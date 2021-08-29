// IF문 좀 대신 써줘
// https://www.acmicpc.net/problem/19637

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<string> name(n + 1);
	vector<int> point(n + 1);
	for (int i = 1; i <= n; i++) 
		cin >> name[i] >> point[i];
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		int left = 1, right = n;
		while (left < right) {
			int mid = (left + right) / 2;
			if (p <= point[mid])
				right = mid;
			else
				left = mid + 1;
		}
		cout << name[right] << '\n';
	}
}

// 일정 전투력 이하에 칭호를 주는 테이블이 있을 때, 주어진 전투력에 칭호 부여하기

// 칭호 개수는 10만, 전투력 상한은 10억 - 배열 형태가 아닌 이분 탐색으로 접근해야 함
// 이분 탐색 방법은 일반적인 방식과 비슷함 - 개별 값이 아닌 인덱스 형태로 접근하는 것이 다르지만
// 우선 칭호와 전투력 상한을 입력받고, 배열에 저장하기 - 같은 인덱스를 볼 수 있도록
// 이후 전투력을 받은 후 left는 1, right는 n으로 두고 이분 탐색을 시작한다
// 만약 현재 전투력이 mid 인덱스의 전투력 이하라면 right를 mid로 당기고, 그렇지 않다면 left를 mid + 1로 당긴다
// 이렇게 계속 돌리다가 두 포인터가 겹치면 right에 있는 칭호 출력하기