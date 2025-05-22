// Свидание
// https://www.acmicpc.net/problem/29220

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k, n;
	cin >> k >> n;
	int sum = 0, minn = 987654321;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		minn = min(minn, p);
		sum += p;
	}
	cout << (sum - minn >= k ? "YES" : "NO") << '\n';
}

// 주어진 지폐 중 하나를 뺐을 때 합이 k보다 작아지는지 확인하기