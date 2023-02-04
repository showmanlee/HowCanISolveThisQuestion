// 2022년이 아름다웠던 이유
// https://www.acmicpc.net/problem/27065

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		bool res = false;
		int sum = 0;
		vector<int> nums;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				sum += i;
				nums.push_back(i);
			}
		}
		if (sum > n) {
			res = true;
			for (int p : nums) {
				int ssum = 0;
				for (int i = 1; i < p; i++) {
					if (p % i == 0) {
						ssum += i;
					}
				}
				if (ssum > p) {
					res = false;
					break;
				}
			}
		}
		cout << (res ? "Good Bye" : "BOJ 2022") << '\n';
	}
}

// 주어진 수가 과잉수이며 자기 자신을 제외한 모든 약수가 부족수거나 완전수인지 판정하기

// 자기 자신을 제외한 약수들의 합이 자기 자신보다 작은 수를 부족수, 자기 자신보다 큰 수를 과잉수, 자기 자신과 같은 수를 완전수라고 하자
// 이를 이용해 약수와 약수의 약수를 구해서 더해서 판정해봅시다