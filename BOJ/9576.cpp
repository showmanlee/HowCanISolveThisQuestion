// 책 나눠주기
// https://www.acmicpc.net/problem/9576

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

bool sorter(pr a, pr b) {
	if (a.second != b.second)
		return a.second < b.second;
	return a.first < b.first;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, m;
		cin >> n >> m;
		vector<bool> books(n + 1);
		vector<pr> people(m);
		for (int i = 0; i < m; i++)
			cin >> people[i].first >> people[i].second;
		sort(people.begin(), people.end(), sorter);
		int res = 0;
		for (pr p : people) {
			for (int i = p.first; i <= p.second; i++) {
				if (!books[i]) {
					res++;
					books[i] = true;
					break;
				}
			}
		}
		cout << res << '\n';
	}
}

// 1~n번의 번호가 적힌 책들을 각자 받고 싶은 책 번호 범위가 다른 m명의 학생에게 줄 때, 줄 수 있는 책의 최대 개수는?

// 주어진 범위를 정렬한 후, 각 학생의 범위를 순회하며 맨 처음으로 빈 책을 해당 학생에게 주면 됨
// 문제는 정렬 방식 - a, b는 a <= b임이 보장된 상태
// a를 우선으로 정렬하면 넓은 범위를 가진 학생에 의해 좁은 범위를 가진 학생이 책을 받지 못할 위험이 있음(1-3, 1-3, 2-2)
// b를 우선으로 정렬하면 이러한 문제를 막을 수 있음 - 각 학생이 마지막 우선순위로 받는 책은 b이므로, 마지막 우선순위가 먼저 필요한 학생에게 양보
// 각 학생들의 범위를 pair로 받고 이를 second -> first 순으로 정렬한 다음, 해당 범위들을 순회하며 첫 번째로 발견한 빈 책을 주고 res++
// 이렇게 돌린 res를 출력하기