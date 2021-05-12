// 소수의 연속합
// https://www.acmicpc.net/problem/1644

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> prime(4000001, true);
	vector<int> pl;
	prime[0] = prime[1] = false;
	for (int i = 2; i <= 4000000; i++) {
		if (prime[i]) {
			pl.push_back(i);
			for (int j = i * 2; j <= 4000000; j += i)
				prime[j] = false;
		}
	}
			
	int n;
	cin >> n;
	int res = 0, sum = 0;
	int l = 0, r = 0;
	while (true) {
		if (sum == n)
			res++;
		if (r == pl.size())
			break;
		if (sum >= n) {
			sum -= pl[l];
			l++;
		}
		else {
			sum += pl[r];
			r++;
		}
	}
	cout << res << '\n';
}

// n을 연속된 소수의 합으로 나타낼 수 있는 가짓수는?
// n이 400만까지니 n^2이 아닌 투 포인터의 힘을 빌려야 함 - 그리고 그전에 에라토스테네스로 400만까지의 소수 목록을 배열에 넣어야 함
// 배열 상에 왼쪽/오른쪽을 나타내는 포인터와 해당 포인터간([l, r)) 수들의 합을 나타내는 변수 마련해두기
// 이후 합이 n이 되면 결과 추가하고, 이후 합이 n 이상이면 왼쪽을 늘리고, 그렇지 않으면 오른쪽을 늘린다
// 그 과정에서 r이 배열을 벗어나면 중지