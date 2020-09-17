// 제로
// https://www.acmicpc.net/problem/10773

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> stack;
	int n, e;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> e;
		if (e == 0 && !stack.empty())
			stack.erase(stack.end() - 1);
		else
			stack.push_back(e);
	}
	int ans = 0;
	for (auto p = stack.begin(); p != stack.end(); p++)
		ans += *p;
	cout << ans;
}

// 0을 외치면 초기화되는 마법의 벡터