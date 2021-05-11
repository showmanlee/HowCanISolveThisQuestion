// 소-난다!
// https://www.acmicpc.net/problem/19699

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool nprime[10001];
int cows[10];
bool order[10];
int n, m;
vector<int> res;

void choice(int p) {
	if (p > m) {
		int s = 0;
		for (int i = 0; i < n; i++) {
			if (order[i] != 0)
				s += cows[i];
		}
		if (!nprime[s])
			res.push_back(s);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (order[i] == 0) {
			order[i] = p;
			choice(p + 1);
			order[i] = 0;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	nprime[0] = nprime[1] = true;
	for (int i = 2; i <= 100; i++) {
		if (!nprime[i]) {
			for (int j = i * 2; j <= 10000; j += i)
				nprime[j] = true;
		}
	}
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> cows[i];
	choice(1);
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	if (res.empty())
		cout << -1;
	else {
		for (int i : res)
			cout << i << ' ';
	}
	cout << '\n';
}

// 무게가 다른 n마리의 소 중 m마리의 무게 합이 소수인 경우 출력하기
// 일단 에라토스테네스를 이용해 10000까지의 소수 판정 - 각 소의 최대 무게가 1000
// 이후 브포로 m마리를 선택한 후, 그 합이 소수인 경우 결과 배열에 누적
// 이후 해당 배열에서 중복을 제거한 값이 결과