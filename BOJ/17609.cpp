// 회문
// https://www.acmicpc.net/problem/17609

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, bool> prr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int res = 2;
		queue<prr> q;
		q.push({ {0, s.length() - 1}, false });
		while (!q.empty()) {
			int left = q.front().first.first;
			int right = q.front().first.second;
			bool miss = q.front().second;
			q.pop();
			if (left > right) {
				res = (miss ? 1 : 0);
				break;
			}
			if (s[left] == s[right])
				q.push({ {left + 1, right - 1}, miss });
			else if (!miss) {
				q.push({ {left, right - 1 }, true });
				q.push({ {left + 1, right }, true });
			}
		}
		cout << res << '\n';
	}
}

// 주어진 문자열이 회문(팰린드롬)인지, 아닌지, 한 글자만 지우면 회문이 되는 유사 회문인지 확인하기
// 유사 회문이라는 것은 일반적인 회문 판정(양 끝에서 시작해서 점점 좁혀오며 확인)에서 한 번의 기회가 더 주어진다는 것
// 여기서 기회를 어디에 줄 것인지에 따라 두 경로로 나뉜다 - left + 1 or right - 1
// 따라서 일반적인 반복문이 아닌 큐를 이용해 판정해보자
// 큐에는 left, right와 더불어 유사 회문이 되었는지를 확인하는 miss도 함께 저장해준다
// 큐 순회 중 left > right가 되면(정상적인 회문임이 확인되면) 성공 판정
// 만약 left / right의 글자가 같으면 두 인덱스를 모두 좁혀주고, 그렇지 않다면(유사 회문 기회가 있는 경우) 둘중 하나만 줄이는 분기를 만들어준다