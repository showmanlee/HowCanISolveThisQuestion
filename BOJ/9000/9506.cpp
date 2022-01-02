// 약수들의 합
// https://www.acmicpc.net/problem/9506

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n;
		cin >> n;
		if (n == -1)
			break;
		vector<int> nums;
		int sum = 0;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				nums.push_back(i);
				sum += i;
			}
		}
		cout << n << ' ';
		if (sum == n) {
			cout << "= ";
			for (int i = 0; i < nums.size(); i++) {
				cout << nums[i];
				if (i != nums.size() - 1)
					cout << " + ";
			}
			cout << '\n';
		}
		else
			cout << "is NOT perfect.\n";
	}
}

// 어떤 수의 약수들의 합이 그 수가 되는 완전수인지 판정하고, 완전수라면 그 약수들 출력하기

// 약수들이야 반복문으로 알아낼 수 있음 - 다만 약수들을 출력할 때 마지막에 + 표시하지 않도록 주의