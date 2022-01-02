// 친구 네트워크
// https://www.acmicpc.net/problem/4195

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

int group[200002];
int gsize[200002];

int finding(int p) {
	if (group[p] == p)
		return p;
	group[p] = finding(group[p]);
	return group[p];
}

void unioning(int a, int b) {
	int pa = finding(a), pb = finding(b);
	if (pa > pb) {
		gsize[pb] += gsize[pa];
		group[pa] = pb;
	}
	else if (pa < pb) {
		gsize[pa] += gsize[pb];
		group[pb] = pa;
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		memset(group, 0, sizeof(group));
		memset(gsize, 0, sizeof(gsize));
		int n;
		cin >> n;
		int idx = 1;
		map<string, int> code;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			if (code.count(a) == 0) {
				code[a] = idx;
				group[idx] = idx;
				gsize[idx] = 1;
				idx++;
			}
			if (code.count(b) == 0) {
				code[b] = idx;
				group[idx] = idx;
				gsize[idx] = 1;
				idx++;
			}
			unioning(code[a], code[b]);
			cout << gsize[finding(code[a])] << '\n';
		}
	}
}

// 두 사람의 네트워크 관계가 이어서 주어질 때, 두 사람이 소속된 네트워크에 있는 사람 구하기
// union-find 문제 - 그러나 노드 번호가 번호가 아닌 문자열로 주어짐
// map을 이용해 새로운 사람이 나올 때마다(code.count(a) == 0) 순차적으로 번호 부여 - union-find는 이전처럼 번호 기반으로 작성
// 최대로 등장할 수 있는 사람은 20만(관계 수 * 2)
// 그런데 입력마다 그룹의 크기를 구해야 하는데, 관계가 10만 개 있으니 일일히 group의 크기를 측정하면 시간 초과
// 이를 막기 위해 그룹의 크기를 저장하는 배열을 별도로 만들어, union 과정에서 합쳐지는 그룹에 두 그룹의 크기를 갱신하기
// 따라서 이 문제는 현실에서의 분리집합 문제라고 볼 수 있음(?)