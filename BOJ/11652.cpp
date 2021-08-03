// 카드
// https://www.acmicpc.net/problem/11652

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	map<long long, long long> cnt;
	long long maxi = 0, maxn = 0;
	for (int i = 0; i < n; i++) {
		long long p;
		cin >> p;
		cnt[p]++;
		if (cnt[p] > maxn) {
			maxi = p;
			maxn = cnt[p];
		}
		else if (cnt[p] == maxn && p < maxi)
			maxi = p;
	}
	cout << maxi << '\n';
}

// 주어진 n개의 정수 중 가장 많이 나온 정수는?

// 정수가 long long 범위에 있기에 일반적인 방법으로 인덱스화 하는 것은 불가능
// 현재까지 나온 최대 개수와 그 개수를 가진 수를 저장하여 결과를 얻어내자 - 카운팅은 map을 활용하고
// 만약 최대 개수가 경신되었다면 최대 개수와 그 개수를 가진 수를 모두 갱신하고, 최대 개수 타이가 나왔다면 기존 결과가 현재 수보다 큰 경우에 갱신하기
// 이렇게 돌린 후 나온 결과가 답
// long long 처리에 주의