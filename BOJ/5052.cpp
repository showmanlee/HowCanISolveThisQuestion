// 전화번호 목록
// https://www.acmicpc.net/problem/5052

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct trie {
	trie* next[10];
	trie() {
		for (int i = 0; i < 10; i++)
			next[i] = NULL;
	}
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		trie* next[10];
		for (int i = 0; i < 10; i++)
			next[i] = NULL;
		int n;
		cin >> n;
		vector<string> nums(n);
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
			if (next[nums[i][0] - '0'] == NULL)
				next[nums[i][0] - '0'] = new trie;
			trie* ptr = next[nums[i][0] - '0'];
			for (int j = 1; j < nums[i].length(); j++) {
				if (ptr->next[nums[i][j] - '0'] == NULL)
					ptr->next[nums[i][j] - '0'] = new trie;
				ptr = ptr->next[nums[i][j] - '0'];
			}
		}
		bool res = true;
		for (int i = 0; i < n; i++) {
			trie* ptr = next[nums[i][0] - '0'];
			for (int j = 1; j < nums[i].length(); j++)
				ptr = ptr->next[nums[i][j] - '0'];
			for (int i = 0; i < 10; i++)
				if (ptr->next[i] != NULL)
					res = false;
			if (!res)
				break;
		}
		cout << (res ? "YES" : "NO") << '\n';
	}
}

// 주어진 전화번호 목록이 일관성이 있는가(한 전화번호가 다른 전화번호 전체로 시작하지 않는가)

// 한 테케 당 번호 수가 10000개까지 주어질 수 있기에 n^2 접근은 불가능
// 대신 다음에 등장할 수 있는 문자 목록을 트리 형태로 표현한 '트라이' 자료구조를 활용하면 빠르게 처리할 수 있다
// 이를 위해 트라이 노드 자료구조를 만들자 - 다음에 들어갈 노드(문자)를 저장하는 10칸짜리 노드 포인터 배열(처음엔 모두 NULL)
// 루트에도 10칸짜리 노드 포인터 배열을 만들어서 처음에 들어갈 곳을 마련
// 이후 전화번호를 입력받을 때 문자를 순회하며 NULL 상태로 있던 칸에 새 노드를 동적 할당한다
// 입력을 마친 후 다시 전화번호를 순회하며 트라이를 타는데, 만약 마지막으로 도달한 트라이 노드의 포인터 배열이 모두 NULL이라면 일관성이 있고, 그렇지 않다면 일관성이 없는 것
// 일관성이 없는 것이 확인되면 바로 NO 출력