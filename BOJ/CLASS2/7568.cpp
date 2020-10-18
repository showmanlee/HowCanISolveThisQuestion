// 덩치
// https://www.acmicpc.net/problem/7568

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<vector<int>> people(n, vector<int>(2));
	vector<int> order(n, 1);
	for (int i = 0; i < n; i++)
		cin >> people[i][0] >> people[i][1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (people[i][0] < people[j][0] && people[i][1] < people[j][1])
				order[i]++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << order[i] << ' ';
	cout << '\n';
}

// 사람은 단 50명