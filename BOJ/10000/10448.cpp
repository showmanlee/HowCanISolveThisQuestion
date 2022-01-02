// 유레카 이론
// https://www.acmicpc.net/problem/10448

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> triangle(45);
	for (int i = 1; i < 45; i++)
		triangle[i] = triangle[i - 1] + i;
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		bool res = false;
		for (int i = 1; i < 45; i++)
			for (int j = i; j < 45; j++)
				for (int k = j; k < 45; k++)
					if (triangle[i] + triangle[j] + triangle[k] == n)
						res = true;
		cout << res << '\n';
	}
}

// 어떤 자연수를 3개의 삼각수의 합으로 나타낼 수 있는가?
// 자연수의 범위가 1000까지 - T44 == 990이므로 부담없이 44^3의 브루트포스로 알아볼 수 있음