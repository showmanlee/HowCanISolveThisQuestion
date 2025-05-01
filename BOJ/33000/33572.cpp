// 자세히 보아야 예쁘다
// https://www.acmicpc.net/problem/33572

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	long long m;
	cin >> n >> m;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		long long p;
		cin >> p;
		p--;
		sum += p;
	}
	cout << (sum >= m ? "DIMI" : "OUT") << '\n'; 
}

// i번째 사람에게 v[i] 시간 이상을 투자하지 않고 m시간을 볼 수 있는지 구하기