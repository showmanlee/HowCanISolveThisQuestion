// 수 이어가기
// https://www.acmicpc.net/problem/2635

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> res;
	for (int i = 0; i <= n; i++) {
		vector<int> v;
		v.push_back(n);
		v.push_back(i);
		int idx = 1;
		while (true) {
			int p = v[idx - 1] - v[idx];
			if (p < 0)
				break;
			v.push_back(p);
			idx++;
		}
		if (res.size() < v.size())
			res = v;
	}
	cout << res.size() << '\n';
	for (int i : res)
		cout << i << ' ';
	cout << '\n';
}

// 첫 번째 수와 두 번째 수를 정한 뒤, 세 번째 수부터는 앞 두 수의 차가 음수가 나오기 전까지 계속 이어가는 수열을 만들려고 한다
// 첫 번째 수가 주어졌을 때, 위와 같은 방식으로 만들 수 있는 가장 긴 수열 출력하기

// 0부터 첫 번째 수까지 계속 돌려보며 수열을 만들어봐야 함 - 첫 번째 수를 초과하면 세 번째 수가 음수가 나오므로 의미가 없음
// 수열에 0이 나올 수 있음에 주의 - 0이 나오면 그 다음 수는 0 이전 수(이전 수 - 0)고, 그 다음에는 음수가 나와(0 - 이전 수) 자연스럽게 정지됨
// 아무튼 문제에 나온 대로 수열을 만들어가다가, 만들어진 수열이 현재 최대 수열보다 길다면 최대 수열로 저장하기